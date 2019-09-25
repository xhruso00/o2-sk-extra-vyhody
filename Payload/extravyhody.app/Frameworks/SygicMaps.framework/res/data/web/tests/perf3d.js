var node = (typeof module !== 'undefined');
var WebSocketClient = node && require('websocket').client;
var Sdk = node ? require("./../common/sdk").Sdk : Sdk;
window = node ? {} : window;

window.global = {pass:-1, lastFrame:0, refFrame:0, refTime:0, measurement:[], measurementFps:[]};

var secondTimer, programTimer;

//Sdk.EnableEcho();

Sdk.Connect(WebSocketClient, "ws://localhost:18279/")
  .then( () => Sdk.GetVersion() )
  .then( (json) => window.global.version = json )
  .then( startTimers )
  .catch( () => console.log("STATUS: Connection failed") );

Sdk.on("gl.currentFrame", (obj) => 
{
  var f = obj.currentFrame;

  if (!window.global.lastFrame)
  {
    window.global.lastFrame = f;
    return;
  }
  var diff = f - window.global.lastFrame;
  window.global.lastFrame = f;
  pushFramerate(diff);
});

var scenario = [
  () => ResetView(),
  () => Begin(),
  () => Sdk.MapView.SetZoom(18),
  () => Sdk.MapView.SetTilt(90),
  () => Sdk.MapView.SetRotation(90),
  () => Sdk.MapView.SetRotation(180),
  () => Sdk.MapView.SetRotation(270),
  () => Sdk.MapView.SetRotation(0),

  () => Sdk.MapView.SetZoom(15),
  () => Sdk.MapView.SetRotation(90),
  () => Sdk.MapView.SetRotation(180),
  () => Sdk.MapView.SetRotation(270),
  () => Sdk.MapView.SetRotation(0),

  () => Sdk.MapView.SetTilt(0),

  () => Sdk.MapView.SetZoom(12),

  () => Sdk.MapView.SetRotation(90),
  () => Sdk.MapView.SetRotation(180),
  () => Sdk.MapView.SetRotation(270),
  () => Sdk.MapView.SetRotation(0),

  () => Sdk.MapView.SetZoom(8),
  () => Sdk.MapView.SetZoom(5),
  () => Sdk.MapView.SetZoom(2),
  () => Sdk.MapView.SetZoom(1),
  () => End(),
  () => Sdk.MapView.SetZoom(17),
  () => 0 // cakaj
];

function startTimers()
{
  // workaround pre iOS, v jednom frame sa nesmu naraz posielat dva ws packety - chybna implementacia ws
  setTimeout(() =>
    secondTimer = setInterval(()=>
    {
      if (Sdk.isConnected())
        Sdk.GL.GetCurrentFrame();
    }, 1000)
  , 153);

  programTimer = setInterval(()=>
  {
    if (!Sdk.isConnected())
      return;

    task = scenario.shift();
    task();
    scenario.push(task);
  }, 3000);
}

function ResetView()
{
  // Bratislava
  Sdk.MapView.SetAnimationDuration(1) // 1 sekunda na animaciu
  .then( () => Sdk.MapView.SetPosition(48.14816, 17.10674) )
  .then( () => Sdk.MapView.SetZoom(17) )
  .then( () => Sdk.MapView.SetTilt(0) )
  .then( () => Sdk.MapView.SetRotation(0) )
}

function Begin()
{
  window.global.pass++;
  pushSeries(window.global.pass);
  window.global.refFrame = window.global.lastFrame;
  window.global.refTime = (new Date()).getTime();
}

function End()
{
  var totalFramesPerTest = window.global.lastFrame - window.global.refFrame;
  var totalTimePerTest = (new Date()).getTime() - window.global.refTime;
  pushScenario({pass: window.global.pass, totalFrames:totalFramesPerTest, totalTime:totalTimePerTest});

  if (window.global.pass > 0)
  {
    window.global.measurement.push(totalFramesPerTest);
    window.global.measurementFps.push(totalFramesPerTest/(totalTimePerTest/1000));
  }

  Finish();
}

function Finish()
{
  if (node && window.global.pass == 3)
  {
    clearInterval(secondTimer);
    clearInterval(programTimer);
    console.log("RESULT: " + window.global.measurement.join(", "));
    if (node)
      pushKibana(window.global.measurementFps);

    Sdk.Disconnect();
  }
}

//pushFramerate = (f) => process.stdout.write(f+",");
pushFramerate = (f) => 0;
pushSeries = () => 0;	
pushScenario = (json) => console.log("PASS " + json.pass + ": Total frames " + json.totalFrames + 
    " took " + json.totalTime + " ms");

pushKibana = (meas) =>
{
  var request = require("request");
  var os = require('os');

  meas.sort();

  /*
  window.global.version = 
  { platform: 'win32',
    platformVersion: '6.2',
    applicationId: 'com.sygic.sdk',
    build: 'debug',
    gitrev: 'unknown',
    deviceId: '736D9EA0',
    memoryId: '6219ea4353fb' }
  */

  fixed2 = (n) => Math.floor(n*100)/100;

  var data = {
    "fps_average": fixed2(meas[1]),
    "fps_min": fixed2(meas[0]),
    "fps_max": fixed2(meas[2]),
    "machine": os.hostname(),
    "os": window.global.version.platform + " " + window.global.version.platformVersion,
    "build": window.global.version.build,
    "revision": window.global.version.gitrev,
    "timestamp": new Date().getTime(),
  };

  console.log("Kibana pushing: " + JSON.stringify(data));

  request({
      url: "http://sdk-tools.sygic.com:9200/perf3d/reading",
      method: "POST",
      json: data
  }, (e, d) =>
  {
    if (e || !d || d.statusCode != 201) 
    {
      console.log("Kibana push error: "+e);
      console.log("STATUS: Kibana push failed");
    }
    else
    {
      console.log("Kibana push ok");
      console.log("STATUS: Done");
    }
  });
}
