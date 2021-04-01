userDeleteRandomTicket(char* login, char* password)
{
	int numDeleteTicket;
	lr_save_string(login,"login");
	lr_save_string(password,"password");
	
	web_reg_save_param_ex(
    "ParamName=userSession", 
    "LB/IC=name=\"userSession\" value=\"",
    "RB/IC=\"",
    "Ordinal=1",
	LAST);
	

	web_url("webtours", 
		"URL={Host}/webtours/", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=", 
		"Snapshot=t1.inf", 
		"Mode=HTML", 
		LAST);

	web_set_sockets_option("SSL_VERSION", "TLS1.2");



	web_submit_data("login.pl",
		"Action={Host}/cgi-bin/login.pl",
		"Method=POST",
		"TargetFrame=body",
		"RecContentType=text/html",
		"Referer={Host}/cgi-bin/nav.pl?in=home",
		"Snapshot=t2.inf",
		"Mode=HTML",
		ITEMDATA,
		"Name=userSession", "Value={userSession}", ENDITEM,
		"Name=username", "Value={login}", ENDITEM,
		"Name=password", "Value={password}", ENDITEM,
		"Name=JSFormSubmit", "Value=off", ENDITEM,
		"Name=login.x", "Value=49", ENDITEM,
		"Name=login.y", "Value=7", ENDITEM,
		LAST);
	
	web_reg_save_param_ex(
    "ParamName=totalTicket", 
    "LB/IC=A total of ",
    "RB/IC= scheduled flights.",
    "Ordinal=all",
	LAST);
	
	web_reg_save_param_ex(
    "ParamName=FlyId", 
    "LB/IC=name=\"flightID\" value=\"",
    "RB/IC=\"",
    "Ordinal=all",
	LAST);
	
		web_url("welcome.pl", 
		"URL={Host}/cgi-bin/welcome.pl?page=itinerary", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer={Host}/cgi-bin/nav.pl?page=menu&in=home", 
		"Snapshot=t7.inf", 
		"Mode=HTML", 
		LAST);
	lr_output_message(lr_eval_string("{totalTicket_1}"));
	
	numDeleteTicket = rand() % atoi(lr_eval_string("{totalTicket_1}"))+1;
	
	lr_save_int(numDeleteTicket, "numDelete");
	lr_output_message("%d",numDeleteTicket);
	
	
	web_submit_data("itinerary.pl", 
		"Action={Host}/cgi-bin/itinerary.pl", 
		"Method=POST", 
		"TargetFrame=", 
		"RecContentType=text/html", 
		"Referer={Host}/cgi-bin/itinerary.pl", 
		"Snapshot=t4.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=flightID", "Value={FlyId_1}", ENDITEM, 
		"Name=flightID", "Value={FlyId_2}", ENDITEM, 
		"Name=flightID", "Value={FlyId_3}", ENDITEM, 
		"Name=flightID", "Value={FlyId_4}", ENDITEM, 
		"Name=flightID", "Value={FlyId_5}", ENDITEM, 
		"Name=flightID", "Value={FlyId_6}", ENDITEM, 
		"Name=flightID", "Value={FlyId_7}", ENDITEM, 
		"Name={numDelete}", "Value=on", ENDITEM, 
		"Name=flightID", "Value={FlyId_8}", ENDITEM, 
		"Name=flightID", "Value={FlyId_9}", ENDITEM, 
		"Name=flightID", "Value={FlyId_10}", ENDITEM, 
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
	
	web_url("SignOff Button", 
		"URL={Host}/cgi-bin/welcome.pl?signOff=1", 
		"TargetFrame=body", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer={Host}/cgi-bin/nav.pl?page=menu&in=itinerary", 
		"Snapshot=t23.inf", 
		"Mode=HTML", 
		LAST);

	return 0;
}
