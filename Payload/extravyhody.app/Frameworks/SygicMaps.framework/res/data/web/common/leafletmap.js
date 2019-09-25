leafletMap = function()
{
  this._map = null;

  var _this = this;

  // zial stale pouzivame na niektore prepocty google
  script = document.createElement('script');
  script.setAttribute('src','https://maps.googleapis.com/maps/api/js?key=AIzaSyA5YCStfqf6-KLMm3UJbwRK3Kx6zRxffl8&libraries=geometry');
  document.head.appendChild(script);
  script.onload = () =>
  {
    var link = document.createElement( "link" );
    link.href = "https://maps.api.sygic.com/js/leaflet/1.0.3/leaflet.css";
    link.type = "text/css";
    link.rel = "stylesheet";
    document.getElementsByTagName( "head" )[0].appendChild( link );

    link.onload = function()
    {
      script = document.createElement('script');
      script.setAttribute('src','https://maps.api.sygic.com/js/leaflet/1.0.3/leaflet.js');
      document.head.appendChild(script);
      script.onload = () =>
      {
        script = document.createElement('script');
        script.setAttribute('src','https://maps.api.sygic.com/js/leaflet.sygic-1.1.0.js');
        document.head.appendChild(script);
        script.onload = () =>
        {
          _this.init();
        }
      }
    }
  }
}

leafletMap.prototype.init = () =>
{
  this.overlays = [];
  this._map = L.map('map-canvas');
  L.TileLayer.sygic('ReB29ySB9yUUGdbK9DbiD56RD').addTo(this._map);
  this._map.setView([48.14389, 17.10972], 18); 
  this._map.keyboard.disable();
  this._map.options.scrollWheelZoom = 'center';
  this._popup = L.popup();

  this._map.on('contextmenu',(e) => {
    var c = this._map.getCenter();

    var content = g.popup(c, e.latlng);

    this._popup
    .setLatLng(e.latlng)
    .setContent(content)
    .addTo(_map)
    .openOn(_map);
  });
  
  this._map.on('drag', (e) => lastUser = (new Date).getTime());

  mapLoaded();
}

leafletMap.prototype.clearOverlays = () => 
{
  for (var i in this.overlays)
    this._map.removeLayer(this.overlays);
  this.overlays = [];
};

leafletMap.prototype.addOverlay = (o) => 
{
  o.addTo(this._map);
  this.overlays.push(o);
}

leafletMap.prototype.removeOverlay = (o) =>
{
  var i = this.overlays.indexOf(o);
  if (i != -1)
    this.overlays.splice(i, 1);

  this._map.removeLayer(o); 
}

leafletMap.prototype.drawPoly = (coords, color, alpha) =>
{
  var path = [];
  for (var i=0; i<coords.length; i+=2)
      path.push(new L.LatLng( coords[i+1] / 100000, coords[i] / 100000 ));

  var polyline = new L.Polyline(path, {
      color: color,
      weight: 6,
      opacity: alpha,
      smoothFactor: 1
  });

  polyline.addTo(this._map);
  this.overlays.push(polyline);

  return polyline;
};

leafletMap.prototype.getZoom = () => this._map.getZoom()-1;
leafletMap.prototype.setCenter = (latlon) => this._map.panTo(new L.LatLng(latlon.lat(), latlon.lng()));
//leaflet.prototype.setCenter = (latlon) => map.setView(new L.LatLng(lanlon.lat(), latlon.lng()), 8);
leafletMap.prototype.getCenter = () => { var c = this._map.getCenter(); return new google.maps.LatLng(c.lat, c.lng)};
