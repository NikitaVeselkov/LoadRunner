Action()
{

	web_set_sockets_option("SSL_VERSION", "AUTO");

	web_add_auto_header("Upgrade-Insecure-Requests", 
		"1");

	web_url("WebTours", 
		"URL=http://localhost:8090/WebTours/", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=", 
		"Snapshot=t10.inf", 
		"Mode=HTML", 
		LAST);

	lr_start_transaction("login");

	web_revert_auto_header("Upgrade-Insecure-Requests");

	web_add_header("Origin", 
		"http://localhost:8090");

	web_submit_data("login.pl", 
		"Action=http://localhost:8090/WebTours/login.pl", 
		"Method=POST", 
		"TargetFrame=body", 
		"RecContentType=text/html", 
		"Referer=http://localhost:8090/WebTours/nav.pl?in=home", 
		"Snapshot=t11.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=userSession", "Value=134897.143215877zQDiHHVpiAtVzzzHtVzDcpzDAicf", ENDITEM, 
		"Name=username", "Value=Nikita", ENDITEM, 
		"Name=password", "Value=nikita", ENDITEM, 
		"Name=login.x", "Value=40", ENDITEM, 
		"Name=login.y", "Value=16", ENDITEM, 
		"Name=JSFormSubmit", "Value=off", ENDITEM, 
		LAST);

	lr_end_transaction("login",LR_AUTO);

	lr_start_transaction("goToitinerary");

	web_add_auto_header("Upgrade-Insecure-Requests", 
		"1");

	lr_think_time(11);

	web_url("Itinerary Button", 
		"URL=http://localhost:8090/WebTours/welcome.pl?page=itinerary", 
		"TargetFrame=body", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://localhost:8090/WebTours/nav.pl?page=menu&in=home", 
		"Snapshot=t12.inf", 
		"Mode=HTML", 
		LAST);

	lr_end_transaction("goToitinerary",LR_AUTO);

	lr_start_transaction("deleteChanged");

	web_add_header("Origin", 
		"http://localhost:8090");

	lr_think_time(18);

	web_submit_data("itinerary.pl", 
		"Action=http://localhost:8090/WebTours/itinerary.pl", 
		"Method=POST", 
		"TargetFrame=", 
		"RecContentType=text/html", 
		"Referer=http://localhost:8090/WebTours/itinerary.pl", 
		"Snapshot=t13.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=1", "Value=on", ENDITEM, 
		"Name=flightID", "Value=0-798-NV", ENDITEM, 
		"Name=flightID", "Value=0-1566-NV", ENDITEM, 
		"Name=flightID", "Value=0-2334-NV", ENDITEM, 
		"Name=removeFlights.x", "Value=29", ENDITEM, 
		"Name=removeFlights.y", "Value=9", ENDITEM, 
		"Name=.cgifields", "Value=1", ENDITEM, 
		"Name=.cgifields", "Value=3", ENDITEM, 
		"Name=.cgifields", "Value=2", ENDITEM, 
		LAST);

	lr_end_transaction("deleteChanged",LR_AUTO);

	lr_start_transaction("logout");

	web_url("SignOff Button", 
		"URL=http://localhost:8090/WebTours/welcome.pl?signOff=1", 
		"TargetFrame=body", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://localhost:8090/WebTours/nav.pl?page=menu&in=itinerary", 
		"Snapshot=t14.inf", 
		"Mode=HTML", 
		LAST);

	lr_end_transaction("logout",LR_AUTO);

	return 0;
}