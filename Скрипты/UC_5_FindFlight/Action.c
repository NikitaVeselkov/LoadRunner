Action()
{
	
	lr_start_transaction("UC_5_FindFlight");
	
	homePage();
	
	login();
	
	goToFlight();
	
	findFlight();
	
	logout();
	
	lr_end_transaction("UC_5_FindFlight", LR_AUTO);

	
	
	return 0;
}
