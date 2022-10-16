Action()
{
	lr_start_transaction("UC_4_Login_Logout");

	homePage();
	
	login();
	
	logout();
	
	lr_end_transaction("UC_4_Login_Logout", LR_AUTO);

	return 0;
}
