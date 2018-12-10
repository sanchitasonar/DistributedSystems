

//RMIClient//
import java.sql.*;
import java.rmi.*;
import java.io.*;
import java.util.*; 
import java.util.Vector.*;
import java.lang.*;
import java.rmi.registry.*;
import java.lang.*;

public class client 
{      static String name1,name2,name3,name4 ,name5, name6;
	static int len,cmp;
		public static void main(String args[])
		{
			client c=new client();
			BufferedReader b = new BufferedReader(new InputStreamReader(System.in));
              		int ch;
       		try { 
               		Registry r1 = LocateRegistry.getRegistry ( "localhost", 6000);          
              		DBInterface DI=(DBInterface)r1.lookup("DBServ");
                	do
              		{
		   	 	System.out.println("\n1. Display concatenated string \n2. Display string length\n3. Compare two strings\n4. Exit\nEnter ur choice");
               			ch= Integer.parseInt(b.readLine()); 
            			switch(ch)
            			{
                               
     					case 1:          
          					System.out.println("Enter first string:");	
            					name1=b.readLine();
            					System.out.println("Enter second string:");	
            					name2=b.readLine(); 
            					name3=DI.input(name1,name2);                                
    	  					System.out.println("\nConcatenated String is : ");
          					System.out.print(name3 +"\n");                     
          					break;

					case 2:
						System.out.println("Enter string:");	
            					name4=b.readLine();
						len=DI.input_len(name4); 
						System.out.println("\nString length is : ");
          					System.out.print(len+"\n");                     
          					break;

					case 3: System.out.println("Enter first string:");	
            					name5=b.readLine();
            					System.out.println("Enter second string:");	
            					name6=b.readLine(); 
            					cmp=DI.compare(name5,name6); 
						if(cmp==0)
						          System.out.print("\nStrings are equal\n"); 
						if(cmp!=0)
							 System.out.print("\nStrings are not equal\n"); 
						break;  

					case 4: System.exit(0);                 
    	  					 
				}  
             		}while(ch>0);  
            }
        	catch (Exception e) {}
         
	}
}
			
