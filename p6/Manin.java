import java.lang.*;
import java.io.*;
import java.net.*;

public class Manin {

  public static void main(String args[]) throws Exception {
      String sentence;   
      String modifiedSentence;   
      BufferedReader inFromUser = new BufferedReader( new InputStreamReader(System.in));   
      Socket clientSocket = new Socket();   
      clientSocket.connect(new InetSocketAddress("54.83.207.90", 6969));
      DataOutputStream outToServer = new DataOutputStream(clientSocket.getOutputStream());   
      BufferedReader inFromServer = new BufferedReader(new InputStreamReader(clientSocket.getInputStream()));   
      //sentence = inFromUser.readLine();   
      //   
      modifiedSentence = inFromServer.readLine();   
      System.out.println("FROM SERVER: " + modifiedSentence); 
      sentence = "hello!\n";
      outToServer.writeUTF(sentence); 
      modifiedSentence = inFromServer.readLine();   
      System.out.println("FROM SERVER: " + modifiedSentence); 
      clientSocket.close();
  }
}





























