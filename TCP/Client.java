import java.net.*;
import java.io.*;
import java.util.*;
public class Client {
public static void main (String args[]) {
	Socket s = null;
	try{
		Scanner sc = new Scanner(System.in);
		int serverPort = 7896;
		s = new Socket(args[0], serverPort);
		DataInputStream in = new DataInputStream(s.getInputStream());
		DataOutputStream out = new DataOutputStream(s.getOutputStream());
		String datain = in.readUTF();
		System.out.println(datain) ;
		out.writeUTF(sc.next());
		
		datain = in.readUTF();
		System.out.println(datain);
		out.writeUTF(sc.next());
		datain = in.readUTF();
		System.out.println(datain);
	}catch (UnknownHostException e){
		System.out.println("Sock:"+e.getMessage());
	} catch (EOFException e){
		System.out.println("EOF:"+e.getMessage());
	} catch (IOException e){
		System.out.println("IO:"+e.getMessage());
	} finally {if(s!=null) try {s.close();}catch (IOException e){/*close failed*/}}
}
}
