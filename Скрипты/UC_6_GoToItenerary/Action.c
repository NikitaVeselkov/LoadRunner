Action()
{
	
	
	lr_start_transaction("UC_6_GoToItenerary");
	
	homePage();
	
	login();
	
	goToFlight();
	
	goToitinerary();
	
	logout();
	
	
	
	
	lr_end_transaction("UC_6_GoToItenerary", LR_AUTO);


	return 0;
}
