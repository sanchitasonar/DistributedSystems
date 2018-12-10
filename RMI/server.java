

//RMI Server //
import java.sql.*;
import java.sql.Connection;
import java.rmi.*;
import java.rmi.Naming.*;
import java.rmi.server.*;
import java.rmi.registry.*;
import java.util.Vector; 
import java.lang.*;

interface DBInterface extends Remote
{
	public String input(String name1,String name2) throws RemoteException;
	public int input_len(String name4) throws RemoteException;
	public int compare(String name5, String name6)  throws RemoteException;

}

public class server extends UnicastRemoteObject implements DBInterface
{
	int flag=0,n,i,j;
	int len,cmp;  
	String name3;
	ResultSet r;

	public server() throws RemoteException
	{ try 
      	  { 
		System.out.println("Initializing Server\nServer Ready");
      	  }
      	  catch (Exception e)
          {  
		System.out.println("ERROR: " +e.getMessage());
      	  }
} 

public static void main(String[] args)
{ try 
  { 
	server rs=new server();
	java.rmi.registry.LocateRegistry.createRegistry(6000).rebind("DBServ", rs);
  }
  catch (Exception e)
  {
  	System.out.println("ERROR: " +e.getMessage());
  }
}

public String input(String name1,String name2)
{     
     try{
        	name3=name1.concat(name2);
        }  
           
     catch (Exception e)
     {
             System.out.println("ERROR: " +e.getMessage());
     }
     return name3;
}

public int input_len(String name4)
{     
     try{
        	len=name4.length();
        }  
           
     catch (Exception e)
     {
             System.out.println("ERROR: " +e.getMessage());
     }
     return len;
}

public int compare(String name5, String name6)
{     
     try{
        	cmp=name5.compareTo(name6);
        }  
           
     catch (Exception e)
     {
             System.out.println("ERROR: " +e.getMessage());
     }
     return cmp;
}


}
