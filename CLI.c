CLI()
{
	int countFirstClassUser1,countFirstClassUser2,countFirstClassUser3;
	int i,max;
	countFirstClassUser1=user1("jojo","bean");
	countFirstClassUser2=user1("westy","westy");
	countFirstClassUser3=user1("qwerty","wasd");
		

	if ( countFirstClassUser1>=countFirstClassUser2 && countFirstClassUser1>=countFirstClassUser3) {
			max=1;
		}
	if ( countFirstClassUser2>=countFirstClassUser1 && countFirstClassUser2>=countFirstClassUser3) {
			max=2;
		}
	if ( countFirstClassUser3>=countFirstClassUser1 && countFirstClassUser3>=countFirstClassUser2) {
			max=3;
		}
	lr_output_message("1 :%d", countFirstClassUser1);
	lr_output_message("2 :%d", countFirstClassUser2);
	lr_output_message("3 :%d", countFirstClassUser3);
	
	if (max==1) {
		userDeleteRandomTicket("jojo","bean");
		lr_output_message("Delete user jojo");
	} else if (max==2) {
		userDeleteRandomTicket("westy","westy");
			lr_output_message("Delete user westy");
		} else if (max==3) {
			userDeleteRandomTicket("qwerty","wasd");
				lr_output_message("Delete user qwerty");
		}	
	
	return 0;
}
