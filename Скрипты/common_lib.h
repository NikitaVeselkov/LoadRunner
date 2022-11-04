login (){
	
lr_start_transaction("login");
		
		web_set_sockets_option("SSL_VERSION", "AUTO");
		
		web_revert_auto_header("Upgrade-Insecure-Requests");
		
		web_add_header("Origin", 
			"http://localhost:8090");
	
		lr_think_time(7);
		
		web_reg_find("Text/IC=Welcome, <b>{userLogin}</b>",
			LAST);
		
		web_submit_data("login.pl",
			"Action=http://localhost:8090/WebTours/login.pl",
			"Method=POST",
			"TargetFrame=body",
			"RecContentType=text/html",
			"Referer=http://localhost:8090/WebTours/nav.pl?in=home",
			"Snapshot=t2.inf",
			"Mode=HTML",
			ITEMDATA,
			"Name=userSession", "Value={userSession}", ENDITEM,
			"Name=username", "Value={userLogin}", ENDITEM,
			"Name=password", "Value={userPassword}", ENDITEM,
			"Name=login.x", "Value=0", ENDITEM,
			"Name=login.y", "Value=0", ENDITEM,
			"Name=JSFormSubmit", "Value=off", ENDITEM,
			LAST);


	lr_end_transaction("login",LR_AUTO);


	return 0;
}
logout(){
	lr_start_transaction("logout");

	web_add_header("Upgrade-Insecure-Requests", 
		"1");

	lr_think_time(14);

	web_url("SignOff Button",
		"URL=http://localhost:8090/WebTours/welcome.pl?signOff=1",
		"TargetFrame=body",
		"Resource=0",
		"RecContentType=text/html",
		"Referer=http://localhost:8090/WebTours/nav.pl?page=menu&in=flights",
		"Snapshot=t7.inf",
		"Mode=HTML",
		LAST);

	lr_end_transaction("logout",LR_AUTO);
	
	return 0;
}
homePage(){
	
	lr_start_transaction("homePage");

	web_add_auto_header("Upgrade-Insecure-Requests", 
		"1");

/*Correlation comment - Do not change!  Original value='134875.843175375zQDHzHzpViDDDDDDtVzczpAfHV' Name ='userSession' Type ='RecordReplay'*/
	web_reg_save_param_regexp(
		"ParamName=userSession",
		"RegExp=userSession\\ value=(.*?)>",
		"Ordinal=3",
		SEARCH_FILTERS,
		"Scope=Body",
		"RequestUrl=*/nav.pl*",
		LAST);

	web_url("WebTours", 
		"URL=http://localhost:8090/WebTours/", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=", 
		"Snapshot=t1.inf", 
		"Mode=HTML", 
		LAST);
					
	lr_end_transaction("homePage", LR_AUTO);
	
	
	return 0;
}

goToFlight(){
	lr_start_transaction("goToFlight");

		web_add_auto_header("Upgrade-Insecure-Requests", "1");
	
		lr_think_time(23);
	
		web_url("Search Flights Button", 
			"URL=http://localhost:8090/WebTours/welcome.pl?page=search", 
			"TargetFrame=body", 
			"Resource=0", 
			"RecContentType=text/html", 
			"Referer=http://localhost:8090/WebTours/nav.pl?page=menu&in=home", 
			"Snapshot=t3.inf", 
			"Mode=HTML", 
			LAST);

	lr_end_transaction("goToFlight",LR_AUTO);
	return 0;
}

findFlight(){
	
	lr_start_transaction("findFlight");

		web_add_auto_header("Origin", 
			"http://localhost:8090");
	
		lr_think_time(4);
		
		web_reg_save_param_attrib(
			"ParamName=outboundFlight",
			"TagName=input",
			"Extract=value",
			"Name=outboundFlight",
			"Type=radio",
			"Ordinal=ALL",
			SEARCH_FILTERS,
			"IgnoreRedirections=Yes",
			LAST);

		web_submit_data("reservations.pl", 
			"Action=http://localhost:8090/WebTours/reservations.pl", 
			"Method=POST", 
			"TargetFrame=", 
			"RecContentType=text/html", 
			"Referer=http://localhost:8090/WebTours/reservations.pl?page=welcome", 
			"Snapshot=t4.inf", 
			"Mode=HTML", 
			ITEMDATA, 
			"Name=advanceDiscount", "Value=0", ENDITEM, 
			"Name=depart", "Value={city}", ENDITEM, 
			"Name=departDate", "Value={departDate}", ENDITEM, 
			"Name=arrive", "Value={city}", ENDITEM, 
			"Name=returnDate", "Value={returnDate}", ENDITEM, 
			"Name=numPassengers", "Value=1", ENDITEM, 
			"Name=seatPref", "Value={seatPref}", ENDITEM, 
			"Name=seatType", "Value={seatType}", ENDITEM, 
			"Name=findFlights.x", "Value=61", ENDITEM, 
			"Name=findFlights.y", "Value=9", ENDITEM, 
			"Name=.cgifields", "Value=roundtrip", ENDITEM, 
			"Name=.cgifields", "Value=seatType", ENDITEM, 
			"Name=.cgifields", "Value=seatPref", ENDITEM, 
			LAST);

		lr_think_time(5);
		lr_save_string(lr_paramarr_random("outboundFlight"),"outboundFlight");
			
	lr_end_transaction("findFlight", LR_AUTO);
	return 0;
}
choose_flight(){
	
	lr_start_transaction("choose_flight");

		web_submit_data("reservations.pl_2", 
			"Action=http://localhost:8090/WebTours/reservations.pl", 
			"Method=POST", 
			"TargetFrame=", 
			"RecContentType=text/html", 
			"Referer=http://localhost:8090/WebTours/reservations.pl", 
			"Snapshot=t5.inf", 
			"Mode=HTML", 
			ITEMDATA, 
			"Name=outboundFlight", "Value={outboundFlight}", ENDITEM, 
			"Name=numPassengers", "Value=1", ENDITEM, 
			"Name=advanceDiscount", "Value=0", ENDITEM, 
			"Name=seatType", "Value={seatType}", ENDITEM, 
			"Name=seatPref", "Value={seatPref}", ENDITEM, 
			"Name=reserveFlights.x", "Value=49", ENDITEM, 
			"Name=reserveFlights.y", "Value=10", ENDITEM, 
			LAST);

	lr_end_transaction("choose_flight",LR_AUTO);
	
	return 0;
}

paymentDetails(){
		
	lr_start_transaction("paymentDetails");

		web_revert_auto_header("Origin");
	
		web_revert_auto_header("Upgrade-Insecure-Requests");
		
		web_reg_find("Text=<small><B>Thank you for booking through Web Tours.</B></small>",
		LAST);
	
		web_add_header("Origin", 
			"http://localhost:8090");
	
		lr_think_time(41);
		
		web_submit_data("reservations.pl_3", 
			"Action=http://localhost:8090/WebTours/reservations.pl", 
			"Method=POST", 
			"TargetFrame=", 
			"RecContentType=text/html", 
			"Referer=http://localhost:8090/WebTours/reservations.pl", 
			"Snapshot=t6.inf", 
			"Mode=HTML", 
			ITEMDATA, 
			"Name=firstName", "Value={firstName}", ENDITEM, 
			"Name=lastName", "Value={lastName}", ENDITEM, 
			"Name=address1", "Value={streetAdress}", ENDITEM, 
			"Name=address2", "Value={cityAdress}", ENDITEM, 
			"Name=pass1", "Value={firstName} {lastName}", ENDITEM, 
			"Name=creditCard", "Value={creditCard}", ENDITEM, 
			"Name=expDate", "Value={expDate}", ENDITEM, 
			"Name=oldCCOption", "Value=", ENDITEM, 
			"Name=numPassengers", "Value=1", ENDITEM, 
			"Name=seatType", "Value={seatType}", ENDITEM, 
			"Name=seatPref", "Value={seatPref}", ENDITEM, 
			"Name=outboundFlight", "Value={outboundFlight}", ENDITEM, 
			"Name=advanceDiscount", "Value=0", ENDITEM, 
			"Name=returnFlight", "Value=", ENDITEM, 
			"Name=JSFormSubmit", "Value=off", ENDITEM, 
			"Name=buyFlights.x", "Value=61", ENDITEM, 
			"Name=buyFlights.y", "Value=10", ENDITEM, 
			"Name=.cgifields", "Value=saveCC", ENDITEM, 
			LAST);

	lr_end_transaction("paymentDetails",LR_AUTO);
	
	return 0;
}

goToitinerary(){
	
	web_reg_save_param_attrib(
		"ParamName=deleteFlightID",
		"TagName=input",
		"Extract=value",
		"Name=flightID",
		"Type=hidden",
		"Ordinal=1",
		SEARCH_FILTERS,
		"IgnoreRedirections=Yes",
		LAST);

	lr_start_transaction("goToitinerary");
		web_add_auto_header("Upgrade-Insecure-Requests", "1");
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
	return 0;
}

deleteFirst (){
	lr_start_transaction("deleteFirst");
	
		web_reg_find("Fail=Found",
		"Text/IC=\"flightID\" value=\"{deleteFlightID}",
		LAST);

		web_add_header("Origin", "http://localhost:8090");
		web_submit_form("itinerary.pl", 
			"Snapshot=t13.inf",
			ITEMDATA, 
			"Name=1", "Value=on", ENDITEM,
			"Name=removeFlights.x", "Value=48", ENDITEM, 
			"Name=removeFlights.y", "Value=8", ENDITEM,		
			LAST);
	
	lr_end_transaction("deleteFirst",LR_AUTO);
	
	return 0;
}

generatorData(){
	
	lr_save_string(lr_eval_string("{generatorData}{generatorData}{generatorData}{generatorData}{generatorData}{generatorData}{generatorData}{generatorData}"), "userLogin");
	
	lr_save_string(lr_eval_string("{generatorData}{generatorData}{generatorData}{generatorData}{generatorData}{generatorData}{generatorData}{generatorData}"), "userPassword");
	
	lr_save_string(lr_eval_string("{generatorData}{generatorData}{generatorData}{generatorData}{generatorData}{generatorData}{generatorData}{generatorData}"), "firstName");
	
	lr_save_string(lr_eval_string("{generatorData}{generatorData}{generatorData}{generatorData}{generatorData}{generatorData}{generatorData}{generatorData}"), "lastName");
	
	lr_save_string(lr_eval_string("{generatorData}{generatorData}{generatorData}{generatorData}{generatorData}{generatorData}{generatorData}{generatorData}"), "address");
	
	return 0;
}

goToSignUp(){
	
	lr_start_transaction("goToSignUp");

		web_revert_auto_header("Upgrade-Insecure-Requests");
	
		lr_think_time(12);
	
		web_url("sign up now", 
			"URL=http://localhost:8090/WebTours/login.pl?username=&password=&getInfo=true", 
			"TargetFrame=body", 
			"Resource=0", 
			"RecContentType=text/html", 
			"Referer=http://localhost:8090/WebTours/home.html", 
			"Snapshot=t2.inf", 
			"Mode=HTML", 
			LAST);

	lr_end_transaction("goToSignUp",LR_AUTO);
	
	return 0;
}
registration (){
	
	lr_start_transaction("registration");

		web_add_header("Origin","http://localhost:8090");
	
		web_add_header("Upgrade-Insecure-Requests", "1");
		

	web_reg_find("Text=Thank you, <b>{userLogin}</b>, for registering and welcome to the Web Tours family.",LAST);

		lr_think_time(24);
	
		web_submit_form("login.pl", 
			"Snapshot=t3.inf", 
			ITEMDATA, 
			"Name=username", "Value={userLogin}", ENDITEM, 
			"Name=password", "Value={userPassword}", ENDITEM, 
			"Name=passwordConfirm", "Value={userPassword}", ENDITEM, 
			"Name=firstName", "Value={firstName}", ENDITEM, 
			"Name=lastName", "Value={lastName}", ENDITEM, 
			"Name=address1", "Value={address}", ENDITEM, 
			"Name=address2", "Value={address}", ENDITEM, 
			"Name=register.x", "Value=45", ENDITEM, 
			"Name=register.y", "Value=15", ENDITEM, 
			LAST);

	lr_end_transaction("registration",LR_AUTO);
	
	return 0;
}

regContinue () {

	lr_start_transaction("regContinue");

	web_revert_auto_header("Upgrade-Insecure-Requests");

	web_url("Home Button", 
		"URL=http://localhost:8090/WebTours/welcome.pl?page=menus", 
		"TargetFrame=body", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://localhost:8090/WebTours/login.pl", 
		"Snapshot=t4.inf", 
		"Mode=HTML", 
		LAST);

	lr_end_transaction("regContinue",LR_AUTO);

return 0 ;
}