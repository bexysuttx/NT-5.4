user1(char* login, char* password)
{
	int countFirstClass;
	
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
	
	web_reg_find("Text=A First class", "SaveCount=FirstClass_count", LAST );
	
	
	web_url("welcome.pl", 
		"URL={Host}/cgi-bin/welcome.pl?page=itinerary", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer={Host}/cgi-bin/nav.pl?page=menu&in=home", 
		"Snapshot=t7.inf", 
		"Mode=HTML", 
		LAST);
	
	lr_output_message("user: %s",lr_eval_string( "{FirstClass_count}" ));
	countFirstClass=atoi(lr_eval_string("{FirstClass_count}"));
	
	web_url("SignOff Button", 
		"URL={Host}/cgi-bin/welcome.pl?signOff=1", 
		"TargetFrame=body", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer={Host}/cgi-bin/nav.pl?page=menu&in=itinerary", 
		"Snapshot=t23.inf", 
		"Mode=HTML", 
		LAST);
	
	return countFirstClass;
}
