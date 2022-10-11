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
		"Snapshot=t1.inf", 
		"Mode=HTML", 
		LAST);

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

	lr_start_transaction("registration");

	web_add_header("Origin", 
		"http://localhost:8090");

	web_add_header("Upgrade-Insecure-Requests", 
		"1");

	lr_think_time(29);

	web_submit_data("login.pl", 
		"Action=http://localhost:8090/WebTours/login.pl", 
		"Method=POST", 
		"TargetFrame=info", 
		"RecContentType=text/html", 
		"Referer=http://localhost:8090/WebTours/login.pl?username=&password=&getInfo=true", 
		"Snapshot=t3.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=username", "Value=jojo", ENDITEM, 
		"Name=password", "Value=jojo", ENDITEM, 
		"Name=passwordConfirm", "Value=jojo", ENDITEM, 
		"Name=firstName", "Value=jojo", ENDITEM, 
		"Name=lastName", "Value=Jeje", ENDITEM, 
		"Name=address1", "Value=mira", ENDITEM, 
		"Name=address2", "Value=", ENDITEM, 
		"Name=register.x", "Value=0", ENDITEM, 
		"Name=register.y", "Value=0", ENDITEM, 
		LAST);

	lr_end_transaction("registration",LR_AUTO);

	return 0;
}