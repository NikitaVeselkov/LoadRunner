Action()
{
		
lr_start_transaction("UC_1_BuyTicket");

	homePage();
	login();
	goToFlight();
	findFlight();
	choose_flight();
	paymentDetails();
	goToitinerary(); // нужна для профиля
	logout();
	
	lr_end_transaction("UC_1_BuyTicket", LR_AUTO);


	return 0;
	

}