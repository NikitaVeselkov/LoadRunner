Action()
{
lr_start_transaction("UC_3_SignUp");

	generatorData();
	
	homePage();
	
	goToSignUp();
	
	registration();
	
	regContinue();

lr_end_transaction("UC_3_SignUp", LR_AUTO);

return 0;
}
