#include<iostream>
#include<stdlib.h>
#include<windows.h>
using namespace std;
main()
{


		char ch;
		do{
			system("CLS");
			int i=0;
	string arr[3][3]={{"1","2","3"},{"4","5","6"},{"7","8","9"}};
	

	
do{
	cout<<endl<<endl;

    int a;


cout<<arr[0][0]<<"  | "<<arr[0][1]<<"  | "<<arr[0][2]<<endl;
cout<<"___|____|___"<<endl;
cout<<arr[1][0]<<"  | "<<arr[1][1]<<"  | "<<arr[1][2]<<endl;
cout<<"___|____|___"<<endl;
cout<<arr[2][0]<<"  | "<<arr[2][1]<<"  | "<<arr[2][2]<<endl;
cout<<"   |    |    "<<endl;







cout<<"\nEnter player A"<<endl;
cin>>a;
switch(a)
{
	case 1:
		if(arr[0][0]!="A"&&arr[0][0]!="B")
		{
		arr[0][0]="A";
	    }
	    else{
	    	cout<<"Already Filled try in next turn"<<endl;
		}
		break;
	case 2:
		if(arr[0][1]!="A"&&arr[0][1]!="B")
		{
		arr[0][1]="A";
	    }
	else{
	    	cout<<"Already Filled try in next turn"<<endl;
		}
		break;
	case 3:
		if(arr[0][2]!="A"&&arr[0][2]!="B")
		{
		arr[0][2]="A";
	    }
		else{
	    	cout<<"Already Filled try in next turn"<<endl;
		}
		break;
	case 4:
		if(arr[1][0]!="A"&&arr[1][0]!="B")
		{
		arr[1][0]="A";
	}
	else{
	    	cout<<"Already Filled try in next turn"<<endl;
		}
		break;
	case 5:
		if(arr[1][1]!="A"&&arr[1][1]!="B")
		{
		arr[1][1]="A";
	}
		else{
	    	cout<<"Already Filled try in next turn"<<endl;
		}
		break;
	case 6:
		if(arr[1][2]!="A"&&arr[1][2]!="B")
		{
		arr[1][2]="A";
		}
		else{
	    	cout<<"Already Filled try in next turn"<<endl;
		}
		break;
	case 7:
		if(arr[2][0]!="A"&&arr[2][0]!="B")
		{
		arr[2][0]="A";
		}
		else{
	    	cout<<"Already Filled try in next turn"<<endl;
		}
		break;
	case 8:
		if(arr[2][1]!="A"&&arr[2][1]!="B")
		{
		arr[2][1]="A";
	}
		else{
	    	cout<<"Already Filled try in next turn"<<endl;
		}
		break;
	case 9:
			if(arr[2][2]!="A"&&arr[2][2]!="B")
		{
		arr[2][2]="A";
		}
		else{
	    	cout<<"Already Filled try in next turn"<<endl;
		}
		break;
	default:
		cout<<"Invalid input please try again in next turn"<<endl;
		Sleep(3000);
	
}
if(arr[0][0]==arr[0][1]&&arr[0][1]==arr[0][2]||arr[1][0]==arr[1][1]&&arr[1][1]==arr[1][2]||arr[2][0]==arr[2][1]&&arr[2][1]==arr[2][2]
||arr[0][0]==arr[1][0]&&arr[1][0]==arr[2][0]||arr[0][1]==arr[1][1]&&arr[1][1]==arr[2][1]||arr[0][2]==arr[1][2]&&arr[1][2]==arr[2][2]
||arr[0][0]==arr[1][1]&&arr[1][1]==arr[2][2]||arr[0][2]==arr[1][1]&&arr[1][1]==arr[2][0])
{
	cout<<"***************Congratulations**************\n        Player A won the Game"<<endl;
	break;
}
cout<<"\nEnter player B"<<endl;
cin>>a;
switch(a)
{
	case 1:
		if(arr[0][0]!="A"&&arr[0][0]!="B")
		{
		arr[0][0]="B";
	    }
	    else{
	    	cout<<"Already Filled try in next turn"<<endl;
	    	Sleep(1000);
		}
		break;
	case 2:
		if(arr[0][1]!="A"&&arr[0][1]!="B")
		{
		arr[0][1]="B";
	    }
	else{
	    	cout<<"Already Filled try in next turn"<<endl;
	    		Sleep(1000);
		}
		break;
	case 3:
		if(arr[0][2]!="A"&&arr[0][2]!="B")
		{
		arr[0][2]="B";
	    }
		else{
	    	cout<<"Already Filled try in next turn"<<endl;
	    		Sleep(1000);
		}
		break;
	case 4:
		if(arr[1][0]!="A"&&arr[1][0]!="B")
		{
		arr[1][0]="B";
	}
	else{
	    	cout<<"Already Filled try in next turn"<<endl;
	    		Sleep(1000);
		}
		break;
	case 5:
		if(arr[1][1]!="A"&&arr[1][1]!="B")
		{
		arr[1][1]="B";
	}
		else{
	    	cout<<"Already Filled try in next turn"<<endl;
	    		Sleep(1000);
		}
		break;
	case 6:
		if(arr[1][2]!="A"&&arr[1][2]!="B")
		{
		arr[1][2]="B";
		}
		else{
	    	cout<<"Already Filled try in next turn"<<endl;
	    		Sleep(1000);
		}
		break;
	case 7:
		if(arr[2][0]!="A"&&arr[2][0]!="B")
		{
		arr[2][0]="B";
		}
		else{
	    	cout<<"Already Filled try in next turn"<<endl;
	    		Sleep(1000);
		}
		break;
	case 8:
		if(arr[2][1]!="A"&&arr[2][1]!="B")
		{
		arr[2][1]="B";
	}
		else{
	    	cout<<"Already Filled try in next turn"<<endl;
	    		Sleep(1000);
		}
		break;
	case 9:
			if(arr[2][2]!="A"&&arr[2][2]!="B")
		{
		arr[2][2]="B";
		}
		else{
	    	cout<<"Already Filled try in next turn"<<endl;
	    		Sleep(1000);
		}
		break;
	default :
		cout<<"Invalid input please try again in next turn"<<endl;
		Sleep(3000);
	
}
if(arr[0][0]==arr[0][1]&&arr[0][1]==arr[0][2]||arr[1][0]==arr[1][1]&&arr[1][1]==arr[1][2]||arr[2][0]==arr[2][1]&&arr[2][1]==arr[2][2]
||arr[0][0]==arr[1][0]&&arr[1][0]==arr[2][0]||arr[0][1]==arr[1][1]&&arr[1][1]==arr[2][1]||arr[0][2]==arr[1][2]&&arr[1][2]==arr[2][2]
||arr[0][0]==arr[1][1]&&arr[1][1]==arr[2][2]||arr[0][2]==arr[1][1]&&arr[1][1]==arr[2][0])
{
	cout<<"***************Congratulations**************\n        Player B won the Game"<<endl;
	break;
}

system("CLS");
i++;
}while(i<5);
cout<<"Press Y if you want to contine... "<<endl;
cin>>ch;
}while(ch=='y'||ch=='Y');
}
