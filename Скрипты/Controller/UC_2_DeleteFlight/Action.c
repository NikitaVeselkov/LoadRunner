Action()
{
lr_start_transaction("UC_2_DeleteFlight");

	homePage();

	login();
	
	goToitinerary();
	
	deleteFirst();
	
	
	
	
	

lr_end_transaction("UC_2_DeleteFlight", LR_AUTO);


	return 0;
}