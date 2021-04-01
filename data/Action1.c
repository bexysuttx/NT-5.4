Action1()
{

	web_url("webtours", 
		"URL=http://localhost:1080/webtours/", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=", 
		"Snapshot=t1.inf", 
		"Mode=HTML", 
		LAST);

	web_set_sockets_option("SSL_VERSION", "TLS1.2");

	lr_think_time(5);

	web_submit_data("login.pl", 
		"Action=http://localhost:1080/cgi-bin/login.pl", 
		"Method=POST", 
		"TargetFrame=body", 
		"RecContentType=text/html", 
		"Referer=http://localhost:1080/cgi-bin/nav.pl?in=home", 
		"Snapshot=t2.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=userSession", "Value=131003.527663021zHDitQDpQftVzzzHtAtDApQzDHcf", ENDITEM, 
		"Name=username", "Value=jojo", ENDITEM, 
		"Name=password", "Value=bean", ENDITEM, 
		"Name=JSFormSubmit", "Value=off", ENDITEM, 
		"Name=login.x", "Value=0", ENDITEM, 
		"Name=login.y", "Value=0", ENDITEM, 
		LAST);

	web_url("Itinerary Button", 
		"URL=http://localhost:1080/cgi-bin/welcome.pl?page=itinerary", 
		"TargetFrame=body", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://localhost:1080/cgi-bin/nav.pl?page=menu&in=home", 
		"Snapshot=t3.inf", 
		"Mode=HTML", 
		LAST);

	lr_think_time(9);

	web_submit_data("itinerary.pl", 
		"Action=http://localhost:1080/cgi-bin/itinerary.pl", 
		"Method=POST", 
		"TargetFrame=", 
		"RecContentType=text/html", 
		"Referer=http://localhost:1080/cgi-bin/itinerary.pl", 
		"Snapshot=t4.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=flightID", "Value=14839-819-DP", ENDITEM, 
		"Name=flightID", "Value=92631-15464-AI", ENDITEM, 
		"Name=flightID", "Value=363020-23196-SP", ENDITEM, 
		"Name=flightID", "Value=14827-3103-DP", ENDITEM, 
		"Name=flightID", "Value=92631-38541-AI", ENDITEM, 
		"Name=flightID", "Value=363002-46236-SP", ENDITEM, 
		"Name=flightID", "Value=14839-5435-DP", ENDITEM, 
		"Name=8", "Value=on", ENDITEM, 
		"Name=flightID", "Value=9289-6215-AI", ENDITEM, 
		"Name=flightID", "Value=363002-69313-SP", ENDITEM, 
		"Name=flightID", "Value=14827-7719-DP", ENDITEM, 
		"Name=.cgifields", "Value=6", ENDITEM, 
		"Name=.cgifields", "Value=3", ENDITEM, 
		"Name=.cgifields", "Value=7", ENDITEM, 
		"Name=.cgifields", "Value=9", ENDITEM, 
		"Name=.cgifields", "Value=2", ENDITEM, 
		"Name=.cgifields", "Value=8", ENDITEM, 
		"Name=.cgifields", "Value=1", ENDITEM, 
		"Name=.cgifields", "Value=4", ENDITEM, 
		"Name=.cgifields", "Value=10", ENDITEM, 
		"Name=.cgifields", "Value=5", ENDITEM, 
		"Name=removeFlights.x", "Value=37", ENDITEM, 
		"Name=removeFlights.y", "Value=7", ENDITEM, 
		LAST);

	return 0;
}