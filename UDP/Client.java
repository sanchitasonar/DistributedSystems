import java.net.*;
import java.io.*;

public class Client
{
    
	public static void main(String args[])
	{ 

		DatagramSocket aSocket = null;
		try 
		{
			aSocket = new DatagramSocket();    
			byte [] m = args[0].getBytes();
			InetAddress aHost = InetAddress.getByName(args[1]);
			int serverPort = 8000;                                                 
			DatagramPacket request = new DatagramPacket(m,  m.length, aHost, serverPort);
			aSocket.send(request);  
			System.out.println("request msg: " + new String(request.getData()));
                      
			byte[] buffer = new byte[1000];
			DatagramPacket reply = new DatagramPacket(buffer, buffer.length);
			aSocket.receive(reply);

  		} catch (SocketException e)
			{System.out.println("Socket: " + e.getMessage());
  		} catch (IOException e)
			{System.out.println("IO: " + e.getMessage());
  		} finally 
			{ if(aSocket != null) aSocket.close();}   
    	}
}
