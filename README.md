# o2-sk-extra-vyhody
Class dump of iOS app o2 extra vyhody


To record a new navigation route (obtain own cookie and bearer token):

curl -H 'Host: api.extravyhody.o2.sk' -H 'Content-Type: application/json' -H 'redacted' -H 'User-Agent: extravyhody/3 CFNetwork/978.0.7 Darwin/18.7.0' -H 'Accept: */*' -H 'Accept-Language: en-us' -H 'Authorization: Bearer REDACTED' --data-binary '{
  "street" : "",
  "city" : "",
  "score" : 100,
  "distance" : 3.9000000953674316,
  "end_time" : 1569343337,
  "start_time" : 1569342954,
  "average_speed" : 7,
  "max_speed" : 12,
  "distraction_count" : 0,
  "poi_name" : "Jazda bez navigovania",
  "speeding_count" : 0
}' --compressed 'https://api.extravyhody.o2.sk/api/v6/app/navigation_log'

To obtain token:
curl -H 'Host: api.extravyhody.o2.sk' -H 'Content-Type: application/json' -H 'Cookie:redacted' -H 'Accept-Language: en-us' -H 'Accept: */*' -H 'User-Agent: extravyhody/3 CFNetwork/758.5.3 Darwin/15.6.0' --data-binary '{
  "refresh_token" : "redacted",
  "access_token" : "redacted",
  "device_token" : "redacted"
}' --compressed 'https://api.extravyhody.o2.sk/api/v6/app/login'


Register device token (and use in upper):
curl -H 'Host: api.extravyhody.o2.sk' -H 'Content-Type: application/json' -H 'Cookie: redacted' -H 'Accept-Language: en-us' -H 'Accept: */*' -H 'User-Agent: extravyhody/3 CFNetwork/758.5.3 Darwin/15.6.0' --data-binary '{
  "os" : "ios",
  "device_token" : "redacted"
}' --compressed 'https://api.extravyhody.o2.sk/api/v6/app/register_device_token'
