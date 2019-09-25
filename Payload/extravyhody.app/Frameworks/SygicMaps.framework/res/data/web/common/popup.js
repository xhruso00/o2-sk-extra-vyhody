g.enableRecomputeMonitor = () => Sdk.Send('SetFlags("recompute");\n');
g.enableScoutMonitor = () => Sdk.Send('SetFlags("scout");\n');

g.showDebugConsole = () => g.log(`
<input type="button" value="Enable recompute monitor" onClick="g.enableRecomputeMonitor()">
<input type="button" value="Enable echo" onClick="Sdk.EnableEcho()">
<input type="button" value="Disable echo" onClick="Sdk.DisableEcho()">
<input type="button" value="Enable scout monitor" onClick="g.enableScoutMonitor()">
<input type="button" value="Force scout recompute" onClick="sendPosition(); Sdk.Send('AddRouteDuration(10);\\n');">
`);

g.popup = (origin, target) =>
{
    var cmdTraffic = "Sdk.Traffic.Add("+target.lat.toFixed(5)+", "+target.lng.toFixed(5)+").then( (geom) => onTraffic(geom) );";
    var cmdScout = "Sdk.Route.Info(["+
     "{lat:"+origin.lat.toFixed(6)+", lng:"+origin.lng.toFixed(6) + "}," + 
     "{lat:"+target.lat.toFixed(6)+", lng:"+target.lng.toFixed(6)+ "}]);";
    var cmdCalculate = "Sdk.Route.Set(["+
     "{lat:"+origin.lat.toFixed(6)+", lng:"+origin.lng.toFixed(6) + "}," + 
     "{lat:"+target.lat.toFixed(6)+", lng:"+target.lng.toFixed(6)+ "}]);";
    var cmdDebugConsole = "g.showDebugConsole();";
    var cmdOffline = "Sdk.Route.SetAlternatives(false); Sdk.Route.SetService('offline');"
    var cmdOnline = "Sdk.Route.SetAlternatives(false); Sdk.Route.SetService('online');"
    var cmdCancel = "Sdk.Route.Set([]);"

    // hide popup
    cmdTraffic += "this.parentNode.parentNode.previousSibling.click();";
    cmdScout += "this.parentNode.parentNode.previousSibling.click();";
    cmdCalculate += "this.parentNode.parentNode.previousSibling.click();";
    cmdDebugConsole += "this.parentNode.parentNode.previousSibling.click();";
    cmdCancel += "this.parentNode.parentNode.previousSibling.click();";
    return '<a href="#" onClick="'+cmdTraffic+'">Add traffic</a><br>'+
      '<a href="#" onClick="'+cmdOffline + cmdCalculate+'">Calculate offline route</a><br>'+
      '<a href="#" onClick="'+cmdOnline + cmdCalculate+'">Calculate online route</a><br>'+
      '<a href="#" onClick="'+cmdCancel+'">Cancel route</a><br>'+
      '<a href="#" onClick="'+cmdScout+'">Calculate scout</a><br>'+
      '<a href="#" onClick="'+cmdDebugConsole+'">Show debug console</a>';
}