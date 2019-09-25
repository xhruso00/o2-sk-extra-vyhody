var _client, _connection, _socket, _buffer = "";
var send;
var connected = false;

if (typeof module !== 'undefined')
{
  EventEmitter = require("events");
  emitter = new EventEmitter();
  dispatchEvent = (id, arg) => emitter.emit(id, arg);
} else
{
  dispatchEvent = (id, data) => document.body.dispatchEvent(new CustomEvent(id, {detail:data}));
}

//sleeper = (ms) => function(x) { return new Promise(resolve => setTimeout(() => resolve(x), ms)); };

// nodejs 
function connectNode(WebSocketClient, url)
{
  return new Promise((resolve, reject) => {
    _client = new WebSocketClient();
     
    _client.on('connectFailed', function(error) {
        console.log('Connect Error: ' + error.toString());
        reject();
    });
     
    _client.on('connect', function(connection) {
        _connection = connection;
        send = (msg) => {
          if (_handlersLog && _handlersLog.send)
            _handlersLog.send(msg);

          connection.sendUTF(msg);
        }

        console.log('WebSocket Client Connected');
	connected = true;
        dispatchEvent("sdkConnected");

        connection.on('error', function(error) {
            console.log("Connection Error: " + error.toString());
        });

        connection.on('close', function() {
            console.log('Connection Closed');
	    connected = false;
            dispatchEvent("sdkDisconnected");
        });

        connection.on('message', function(message) {
          _buffer += new String(message.utf8Data);
          var lines = _buffer.split("\n");
          while ( lines.length > 1 )
          {
            var line = lines.shift();

            if (_handlersLog && _handlersLog.receive)
              _handlersLog.receive(line);

            eval(line);
          }
          _buffer = lines.join("\n");
        });
        resolve();
    });

    _client.connect(url);
  });
}

function disconnectNode()
{
  _connection.close();
  return Promise.resolve();
}

// web
function connectWeb()
{
  return new Promise((resolve, reject) => {
    var host = window.location.hostname || "localhost";
    var url = "ws://"+host+":18279/index.html";
//    console.log("Connecting to "+url);
    var notified = false;

    try {
      _socket = new WebSocket(url);
    } catch (e)
    {
      reject();
      return;
    }

    _socket.onmessage = (msg) =>
    {
      _buffer += new String(msg.data);
      var lines = _buffer.split("\n");
      while ( lines.length > 1 )
      {
        var line = lines.shift();
        if (_handlersLog && _handlersLog.receive)
          _handlersLog.receive(line);
        setTimeout(line, 0);
      }
      _buffer = lines.join("\n");
    }

    _socket.onopen = () => { 
      connected = true;
      console.log("Connected!");
      if (!notified)
      {
        dispatchEvent("sdkConnected");

        notified = true;
        resolve();
      }
    };

    _socket.onclose = () => { 
      if (typeof(livetimer) != "undefined")
      {
        clearTimeout(livetimer);
        delete livetimer;
      }
      connected = false;
      dispatchEvent("sdkDisconnected");

      if (!notified)
      {
        notified = true;
        reject();
      }
    };

    send = (msg) => 
    {  
      if (_handlersLog && _handlersLog.send) 
        _handlersLog.send(msg); 
      _socket.send(msg); 

      return true;
    }
  });
}

function disconnectWeb()
{
  _socket.close();
  return Promise.resolve();
}

function jsonToObject(json)
{                     
  if (typeof(json) != "Object")
    return json;

  var out = [];
  for (var i in json)
   out[i] = jsonToObject(json[i]);
}

// handlers
function stringify(json)
{
  json = JSON.stringify(json);
  json = json.replace(/\"([^(\")"]+)\":/g,"$1:");  //This will remove all the quotes
  return json; 
}

_handlers = null;
_handlersLog = null;
handlers = {
  version: {
    report: (json) =>
    {
      _handlers && _handlers.version && _handlers.version.report && _handlers.version.report(json);
    }
  },
  mapView: {
    position: (lon, lat) =>
    {
      _handlers && _handlers.mapView && _handlers.mapView.position && _handlers.mapView.position(lon, lat);
    }
  },
  mapLoader: {
    mapGroupsLoaded: (json) =>
    {
      if (_handlers && _handlers.mapLoader && _handlers.mapLoader.mapGroupsLoaded)
        _handlers.mapLoader.mapGroupsLoaded(json);
      if (_handlersLog && _handlersLog.mapLoader && _handlersLog.mapLoader.mapGroupsLoaded)
        _handlersLog.mapLoader.mapGroupsLoaded(json);
    },
    mapPackagesLoaded: (json) =>
    {
      if (_handlers && _handlers.mapLoader && _handlers.mapLoader.mapPackagesLoaded)
        _handlers.mapLoader.mapPackagesLoaded(json);
      if (_handlersLog && _handlersLog.mapLoader && _handlersLog.mapLoader.mapPackagesLoaded)
        _handlersLog.mapLoader.mapPackagesLoaded(json);
    },
    mapInstallFinished: (json) =>
    {
      if (_handlers && _handlers.mapLoader && _handlers.mapLoader.mapInstallFinished)
        _handlers.mapLoader.mapInstallFinished(json);
      if (_handlersLog && _handlersLog.mapLoader && _handlersLog.mapLoader.mapInstallFinished)
        _handlersLog.mapLoader.mapInstallFinished(json);
    },
    mapUninstallFinished: (json) =>
    {
      if (_handlers && _handlers.mapLoader && _handlers.mapLoader.mapUninstallFinished)
        _handlers.mapLoader.mapUninstallFinished(json);
      if (_handlersLog && _handlersLog.mapLoader && _handlersLog.mapLoader.mapUninstallFinished)
        _handlersLog.mapLoader.mapUninstallFinished(json);
    },
    installedMapPackages: (json) => 
    {
      json = jsonToObject(json);
      if (_handlers && _handlers.mapLoader && _handlers.mapLoader.installedMapPackages)
        _handlers.mapLoader.installedMapPackages(json);
      if (_handlersLog && _handlersLog.mapLoader && _handlersLog.mapLoader.installedMapPackages)
        _handlersLog.mapLoader.installedMapPackages(json);
    }
  },
  onlineio:
  {
    onChunkReceived: (json) => dispatchEvent("online.onChunkReceived", json),
    onChunkTimedOut: (json) => dispatchEvent("online.onChunkTimedOut", json),
    activityStarted: (json) => dispatchEvent("online.activityStarted", json),
    activityFinished: (json) => dispatchEvent("online.activityFinished", json)
  },
  success: (x) => {
    if (_handlers && _handlers.success)
      _handlers.success(x);
    if (_handlersLog && _handlersLog.success)
      _handlersLog.success(x);
  },
  failure: (x) => {
    if (_handlers && _handlers.failure)
      _handlers.failure(x);
    if (_handlersLog && _handlersLog.failure)
      _handlersLog.failure(x);
  },
  trafficAdded: (polyline) => 
  {
    _handlers && _handlers.traffic && _handlers.traffic.added && _handlers.traffic.added(polyline);
  },
  routeStatus: (json) =>
  {
    dispatchEvent("routeStatus", json);
  },
  routeInfo: (json) => {
    dispatchEvent("routeInfo", json);
  },
  routeAvailable: () => {
    dispatchEvent("routeAvailable");
  },
  routeGeometry: (arr, id) => {
    dispatchEvent("routeGeometry", arr);
    _handlers && _handlers.route && _handlers.route.geometry && _handlers.route.geometry(arr, id);
  },
  search: {
    geocode: (json) =>
    {
      _handlers && _handlers.search && _handlers.search.geocode && _handlers.search.geocode(json);
    }
  },
  gl: {
    currentFrame: (f) => {
      dispatchEvent("gl.currentFrame", {currentFrame:f});
//      _handlers && _handlers.gl && _handlers.gl.currentFrame && _handlers.gl.currentFrame(f);
    }
  },
  pong: () => {
    _handlers && _handlers.pong && _handlers.pong();
    if (typeof(livechecktimer) != "undefined")
    {
      clearTimeout(livechecktimer);
      delete livechecktimer;
    }
  }
};

Ping = ()=> 
{
    if (_handlers && _handlers.ping)
      _handlers.ping();
    if (_handlersLog && _handlersLog.ping)
      _handlersLog.ping();
};

Sdk = {
  on:(event, handler) => 
  {
    if (typeof module === 'undefined')
      document.body.addEventListener(event, (e) => handler(e.detail), false);
    else
      emitter.on(event, handler);
  },
  isConnected: () => connected,
  Connect:typeof module === 'undefined' ? connectWeb : connectNode,
  Disconnect:typeof module === 'undefined' ? disconnectWeb : disconnectNode,
  Send:(msg)=>{send(msg); return Promise.resolve()},
  EnableEcho:() => {
    _handlersLog = { 
      send:(x) => console.log("< " + (x+"#").replace("\n#", "")), 
      receive:(x) => { if (1 || x.indexOf(".onlineio.") == -1) console.log("> " + x) }
    };
  },
  DisableEcho:() => {
    _handlersLog = { 
      send:(x) => 0, 
      receive:(x) => 0
    };
  },
  GetVersion: () => new Promise((resolve) => {
      _handlers = { version: { report: (json) => { _handlers = null; resolve(json); }}};
      send("Version.Get();\n");
  }),
  Ping:() => {
    return new Promise((resolve, reject) => {
      _handlers = {pong:() => { clearTimeout(_pingTimeout); _handlers = null; resolve(); }};
      _pingTimeout = setTimeout(reject, 5000);
      send("Ping();\n");
    });
  },
  Traffic:{
    Disable:() => {
      return new Promise((resolve) => {
        _handlers = { success:() => { _handlers = null; resolve(); }};
        send("Traffic.Disable();\n");
      });
    },
    Enable:() => {
      return new Promise((resolve) => {
        _handlers = { success:() => { _handlers = null; resolve(); }};
        send("Traffic.Enable();\n");
      });
    },
    Add:(lat,lon) => {
      return new Promise((resolve) => {
        _handlers = { traffic: {added: (polyline) => { _handlers = null; resolve(polyline); }}};
        send("AddTraffic("+lat+","+lon+");\n");
//        send("TrafficChanged();\n");
      });
    }
  },
  OnlineMaps:{
    Disable:() => {
      return new Promise((resolve) => {
        _handlers = { success:() => { _handlers = null; resolve(); }};
        send("OnlineMaps.Disable();\n");
      });
    },
    Enable:() => {
      return new Promise((resolve) => {
        _handlers = {success:() => { _handlers = null; resolve(); }};
        send("OnlineMaps.Enable();\n");
      });
    },
    Clear:() => {
      return new Promise((resolve) => {
        _handlers = {success:() => { _handlers = null; resolve(); }};
        send("OnlineMaps.Clear();\n");
      });
    }
  },
  MapView: {
    GetPosition:() => {
      return new Promise((resolve, reject) => {
        _handlers = {mapView:{position:(json)=>{_handlers = null; json ? resolve(json) : reject();}}, 
          failure:()=>{_handlers = null; reject();}};
        send("MapView.GetPosition();\n");
      });
    },
    SetPosition:(lat,lon) => {
      return new Promise((resolve, reject) => {
//        _handlers = { failure:()=>{_handlers = null; reject();}, success:()=>{_handlers = null; resolve();}};
        send("MapView.SetPosition("+lat.toFixed(5)+","+lon.toFixed(5)+");\n");
        setTimeout(() => resolve(), 45);
      });
    },
    SetZoom:(zoomLevel) => {
      return new Promise((resolve, reject) => {
//        _handlers = { failure:()=>{_handlers = null; reject();}, success:()=>{_handlers = null; resolve();}};
        send("MapView.SetZoom("+zoomLevel.toFixed(2)+");\n");
        setTimeout(() => resolve(), 45);
      });
    },
    SetTilt:(tilt) => {
      return new Promise((resolve, reject) => {
//        _handlers = { failure:()=>{_handlers = null; reject();}, success:()=>{_handlers = null; resolve();}};
        send("MapView.SetTilt("+tilt.toFixed(2)+");\n");
        setTimeout(() => resolve(), 45);
      });
    },
    SetRotation:(rotation) => {
      return new Promise((resolve, reject) => {
//        _handlers = {failure:()=>{_handlers = null; reject();}, success:()=>{_handlers = null; resolve();}};
        send("MapView.SetRotation("+rotation.toFixed(2)+");\n");
        setTimeout(() => resolve(), 45);
      });
    },
    SetAnimationDuration:(durationSeconds) => {
      return new Promise((resolve, reject) => {
//        _handlers = { failure:()=>{_handlers = null; reject();}, success:()=>{_handlers = null; resolve();}};
        send("MapView.SetAnimationDuration("+durationSeconds.toFixed(2)+");\n");
        setTimeout(() => resolve(), 45);
      });
    },
  },
  GL:{
    GetCurrentFrame:() => {
      return new Promise((resolve, reject) => {
//        _handlers = {failure:()=>{_handlers = null; reject();}, success:(f)=>{_handlers = null; resolve(f);}};
        send("GL.CurrentFrame();\n");
	return Promise.resolve();
      });
    },
  },
  Search: {
    Geocode:(query) => {
      return new Promise((resolve, reject) => {
        _handlers = {search:{geocode:(json)=>{_handlers = null; json ? resolve(json) : reject();}}};
        send("Search.Geocode(\""+query+"\");\n");
      });
    }
  },
  Route: {
    Get:() => {
      return new Promise((resolve, reject) => {
        _handlers = {route:{geometry:(arr, id)=>{_handlers = null; arr ? resolve(arr, id) : reject();}}, 
          failure:()=>{_handlers = null; reject();}};
        send("GetRoute();\n");
      });
    },
    Set:(points) => {
      return new Promise((resolve, reject) => {
//        _handlers = {route:{geometry:(arr, id)=>{_handlers = null; arr ? resolve(arr, id) : reject();}}, 
//          failure:()=>{_handlers = null; reject();}};
        send("Route.Calculate([" + 
          points.map(p=>"\"lat:"+p.lat+" lng:"+p.lng+"\"").join(",")
        + "]);\n");
        resolve();
      });
    },
    Info:(points) => {
      return new Promise((resolve, reject) => {
//        _handlers = {route:{geometry:(arr, id)=>{_handlers = null; arr ? resolve(arr, id) : reject();}}, 
//          failure:()=>{_handlers = null; reject();}};
        send("Route.CalculateInfo(" + stringify(points) + ");\n");
        resolve();
      });
    },
    SetAlternatives:(b) =>
    {
      // true, false
      send("Route.SetAlternatives(" + b + ");\n");
      return Promise.resolve();
    },
    SetService:(service) =>
    {
      // sygic, auto, offline
      send("Route.SetService(\"" + service + "\");\n");
      return Promise.resolve();
    },
    SetMode:(mode) =>
    {
      // car, pedestrian
      send("Route.SetMode(\"" + mode + "\");\n");
      return Promise.resolve();
    },

  },
  Position: {
    SetSpeed: (kmh) => send("GPS.SetSpeed("+kmh+");\n") && Promise.resolve(),
    SetCourse: (heading) => send("GPS.SetCourse("+heading+");\n") && Promise.resolve(),
    SetPosition: (lat, lon) => send("GPS.SetPosition("+Math.floor(lon*100000) + "," + Math.floor(lat*100000) +");\n") && Promise.resolve(),
    SetAll: (lat, lon, kmh, heading) => send(
      "GPS.SetSpeed("+kmh+");\n" +
      "GPS.SetCourse("+heading+");\n" +
      "GPS.SetPosition("+Math.floor(lon*100000) + "," + Math.floor(lat*100000) +");\n") && Promise.resolve()
  },
  MapLoader: {
    GetInstalledPackages:() => {
      return new Promise((resolve, reject) => {
        _handlers = {mapLoader:{installedMapPackages:(json)=>{_handlers = null; resolve(json);}}, 
          failure:()=>{_handlers = null; reject();}};
        send("MapLoader.GetInstalledMapPackages();\n");
      });
    },
    GetMapGroups:() => {
      return new Promise((resolve, reject) => {
        _handlers = {mapLoader:{mapGroupsLoaded:(json)=>{_handlers = null; resolve(json);
        }}, failure:()=>{_handlers = null; reject();}};
        send("MapLoader.GetMapGroups();\n");
      });
    },
    GetMapPackagesForGroup:(id) => {
      return new Promise((resolve) => {
        _handlers = {mapLoader:{mapPackagesLoaded:(json)=>{
          _handlers = null; resolve(json);
        }}};
        send("MapLoader.GetMapPackagesForGroup("+id+");\n");
      });
    },
    InstallMapPackage:(id) => {
      return new Promise((resolve, reject) => {
        _handlers = {mapLoader:{mapInstallFinished:(json)=>{
          // pri prvom stahovani taha aj wcl
          if (json.id == id)
          {
            _handlers = null;
            resolve(json);
          }
        }}, failure:()=>{_handlers = null; reject();}};
        send("MapLoader.InstallMapPackage(\""+id+"\");\n");
      });
    },
    UninstallMapPackage:(id) => {
      return new Promise((resolve) => {
        _handlers = {mapLoader:{mapUninstallFinished:(json)=>{
          resolve(json);
        }}};
        send("MapLoader.UninstallMapPackage(\""+id+"\");\n");
      });
    },
    LoadMapPackage:(id) => {
      return new Promise((resolve, reject) => {
        _handlers = {success:()=>{_handlers = null; resolve();}, failure:()=>{_handlers = null; reject();}};
        send("MapLoader.LoadMapPackage([\""+id+"\"]);\n");
      });
    },
    UnloadMapPackage:(id) => {
      return new Promise((resolve, reject) => {
        _handlers = {success:()=>{_handlers = null; resolve();}, failure:()=>{_handlers = null; reject();}};
        send("MapLoader.UnloadMapPackage([\""+id+"\"]);\n");
      });
    },
  },
  Debugging: {
    EnableOnlineIoLogging:(en) => {
      send("Debugging.EnableOnlineIoLogging("+en+");\n");
      return Promise.resolve();
    }
  }
};

Sdk.Profile = (func) =>
{
  var milliseconds = () =>
  {
    var hrTime = process.hrtime();
    return Math.floor(hrTime[0] * 1000 + hrTime[1] / 1000000);
  }

  var startTime = milliseconds();
  return func()
    .then( (result) => 
    { 
      var endTime = milliseconds(); 
      return [result, endTime-startTime]; 
    })
    .catch( (e) => 
    { 
      var endTime = milliseconds(); 
      return [null, endTime-startTime]; 
    });
}

Sdk.Tools = {
  Profile: Sdk.Profile,

  CheckAndInstallPackage: (region, country) =>
  {
    return Promise.resolve()
    .then( () => Sdk.Tools.GetInstalledPackage(country) )
    .then( () => console.log("Package " + country + " uz je nainstalovane") )
    .then( () => false )
    .catch( () => {
      console.log("Instalujem " + country);
      return Sdk.Tools.InstallPackage(region, country)
      .then( () => true )
    })
    .catch( () => {
      console.log("Nepodarilo sa nainstalovat " + country);
    })
  },

  GetInstalledPackage: (packageName) =>
  {
    return Promise.resolve()
    .then( () => Sdk.MapLoader.GetInstalledPackages())
    .then( (array) => new Promise((resolve, reject) => 
    {  
      var found = array.find(obj => obj.title == packageName);
      found ? resolve(found) : reject(false);
    }))
    .then((package) => foundPackageId = package.id)
    .then(()=>true);
  },

  InstallPackage: (groupName, packageName) =>
  {
    var _packageId = 0;

    return Promise.resolve()
    .then( () => console.log("Ziskavam zoznam regionov") )
    .then( Sdk.MapLoader.GetMapGroups )
    .then( (array) => new Promise((resolve, reject) => 
    {  
      for (var i in array)
        if (array[i] == groupName)
        {
          resolve(i);
          return;
        }
      reject("Neviem najst 'Europe' v zozname regionov");
    }))
    .then( (region) => Sdk.MapLoader.GetMapPackagesForGroup(region) )
    .then( (array) => new Promise((resolve, reject) => 
    {  
      var found = array.find(obj => obj.title == packageName);
      found ? resolve(found) : reject("Neviem najst '" + packageName + "' v zozname krajin pre region '" + groupName + "'");
    }))                                                
    .then((package) => foundPackageId = package.id)
    .then((packageId) => _packageId = packageId)
    .then(() => console.log("Instalujem id="+_packageId))
    .then(() => Sdk.MapLoader.InstallMapPackage(_packageId))
    .then(() => Sdk.MapLoader.LoadMapPackage(_packageId))
    .then(() => true)
  }
}

if (typeof module !== 'undefined')
  module.exports = {Sdk:Sdk};
