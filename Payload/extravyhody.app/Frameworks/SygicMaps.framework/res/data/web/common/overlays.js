/***
LOGSOCKET << "g.log('" << output.m_snapPosition << "');\n";
LOGSOCKET << "g.marker({id:'mark1', text:'Moj text', position:" << output.m_snapPosition << "});\n";
LOGSOCKET << "g.marker({position:" << output.m_snapPosition << "});\n";
LOGSOCKET << "g.drawPolyline({id:'moj1', color:'#ff0000', alpha:1, geometry:" << info.vecGeometry << "]});\n";
LOGSOCKET << "g.drawPolyline({id:'moj1', color:'#ff0000', alpha:0.5, geometry:[" << info.ptFromPosOnRoad << ", " << info.ptToPosOnRoad << "]});\n";
***/

var userOverlays = {};

var logWindow = document.getElementById("debug");
var logLines = [];

var g = {
  drawPolyline:(json) => {
    if (json.id)
    {
      if (userOverlays[json.id])
        map.removeOverlay(userOverlays[json.id]);

      var points = [];
      for (var q in json.geometry)
        points.push(json.geometry[q][0] * 100000, json.geometry[q][1] * 100000);

      userOverlays[json.id] = map.drawPoly(points, json.color ? json.color : "#0000b0", json.alpha ? json.alpha : 0.5);
    } else
    {
      map.drawPoly(json.geometry, json.color ? json.color : "#0000b0", json.alpha ? json.alpha : 0.5);
    }
  },
  logClear:() =>
  {
    logLines = [];
    logWindow.innerHTML = "";
  },
  log:(info) =>
  {
    if (typeof(info)!="string" && info.length)
    {
      while (info.length)
        logLines.push(info.shift());
    } else
      logLines.push(info);

    if (logLines.length>10)
      logLines.shift();
    logWindow.innerHTML = logLines.join("\n");
    logWindow.style.display = "";
  },
  marker:(json) =>
  {
    var m = L.marker([json.position[1], json.position[0]]);
    if (json.text)
    {
      m.bindTooltip(json.text, 
      {
        permanent: true, 
        direction: 'right'
      });
    }
    
    if (json.id)
    {
      if (userOverlays[json.id])
        map.removeOverlay(userOverlays[json.id]);

      userOverlays[json.id] = m;

      map.addOverlay(userOverlays[json.id]);
    } else
    {
      map.addOverlay(m);
    }
  }
};
