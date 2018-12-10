import java.net.*;
import java.io.*;
public class Server {
	public static void main (String args[]) {
	try{
		int serverPort = 7896;
		ServerSocket listenSocket = new ServerSocket(serverPort);
		while(true) {
			Socket clientSocket = listenSocket.accept();
			Connection c = new Connection(clientSocket);
		}
	} catch(IOException e) {System.out.println("Listen :"+e.getMessage());}
	}
}
class Connection extends Thread {
	DataInputStream in;
	DataOutputStream out;
	Socket clientSocket;
	public Connection (Socket aClientSocket) {
		try {
			clientSocket = aClientSocket;
			in = new DataInputStream( clientSocket.getInputStream());
			out = new DataOutputStream( clientSocket.getOutputStream());
			this.start();
		} catch(IOException e) {System.out.println("Connection:"+e.getMessage());}
	}
	public void run(){
		try {
			String dataout = "WELCOME TO SBI BANK\nPlease Enter your account no. ";
			out.writeUTF(dataout);
			String datain = in.readUTF();
			System.out.println("Account no. " + datain);
			dataout = "Welcome ABC\nSelect \n1.Credit \n2.Debit \n3.Check balance \n4.Exit";
			out.writeUTF(dataout);
			datain = in.readUTF();
			switch(datain){
				case "1":  dataout = "credit";
					out.writeUTF(dataout);
					break;
				case "2":	dataout = "debit";
					out.writeUTF(dataout);
					break;
				case "3":	dataout = "check balance";
					out.writeUTF(dataout);
					break;
				case "4":	dataout = "exit";
					out.writeUTF(dataout);
					break;
				default :  dataout = "Invalid option";
					out.writeUTF(dataout); 
			};
		} catch(EOFException e) {System.out.println("EOF:"+e.getMessage());
		} catch(IOException e) {System.out.println("IO:"+e.getMessage());
		} finally { try {clientSocket.close();}catch (IOException e){ /*close failed*/ }}
	}
}
