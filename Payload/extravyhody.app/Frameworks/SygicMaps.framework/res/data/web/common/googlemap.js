googleMap = function()
{
  this._map = null;
  this.overlays = [];

  script = document.createElement('script');
  script.setAttribute('src','https://maps.googleapis.com/maps/api/js?key=AIzaSyA5YCStfqf6-KLMm3UJbwRK3Kx6zRxffl8&libraries=geometry');
  document.head.appendChild(script);

  var _this = this;
  script.onload = () =>
  {
    google.maps.event.addDomListener(window, 'load', () => _this.init());
  }
}

googleMap.prototype.init = () =>
{
  var mapOptions = {
    center: new google.maps.LatLng(48.14389, 17.10972),
    zoom: 20,
    keyboardShortcuts: false,
    disableDefaultUI: true
  };
  
  this._map = new google.maps.Map(document.getElementById("map-canvas"), mapOptions);
  google.maps.event.addListener(this._map, 'dragstart', () => lastUser = (new Date).getTime() );
  google.maps.event.addListener(this._map, "rightclick", (e) => 
  {
    if (connected)
      Sdk.Traffic.Add(e.latLng.lat().toFixed(5), e.latLng.lng().toFixed(5))
        .then( (geom) => onTraffic(geom) );
  });
};

googleMap.prototype.getZoom = () => this._map.getZoom();
googleMap.prototype.getCenter = () => this._map.getCenter();
googleMap.prototype.setCenter = (latlon) => this._map.setCenter(latlon);

googleMap.prototype.drawPoly = (coords, color, alpha) =>
{
    var polyOptions = {
        strokeColor: color,
        strokeOpacity: alpha,
        strokeWeight: 6
    };

    var poly = new google.maps.Polyline(polyOptions);
    var path = poly.getPath();
    for (var i=0; i<coords.length; i+=2)
        path.push(new google.maps.LatLng( coords[i+1] / 100000, coords[i] / 100000 ));

    poly.setMap(this._map);
    this.overlays.push(poly);
    return poly;
}

googleMap.prototype.clearOverlays = () =>
{
  while(this.overlays.length) 
    this.overlays.pop().setMap(null);
  this.overlays = [];
}

googleMap.prototype.removeOverlay = (o) =>
{
  o.setMap(null); 
}
