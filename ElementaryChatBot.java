import java.util.Scanner;
public class ElementaryChatBot{
    public static void main(String[] args){
        Scanner scanner=new Scanner(System.in);

        System.out.println("Welcome to Edubot - Your Admission Assistant!");
        System.out.println("Type 'exit' anytime to end the conersation \n");
        while (true){
            System.out.print("You:");
            String input = scanner.nextLine().toLowerCase();

            if(input.contains("exit")|| input.contains("bye")){
                System.out.println("EduBot: Thank you for your interest! All the best for your future!");
                break;
            }else if(input.contains("courses")|| input.contains("programs") || input.contains("offer")){
                System.out.println("EduBot: We offer B.Teh,BBA,BCA, MCA,and MTech programs");

            }else if(input.contains("admission")|| input.contains("process")|| input.contains("apply")){
                System.out.println("EduBot: You can apply online through our official website.The process includes registration , document upload, and payment of application fees");
            }else{
                System.out.println("EduBot: I'm sorry ,I didn't understand that. Could you please rephrase?");

            }
        }
        scanner.close();
    }
}