
importpublic class SimpleExpertSystem{
    public static void main(String[] args){
         Scanner scanner = new Scanner(System.in);

         System.out.println("Welcome to the Hospital Expert System");
         System.out.print("Do you have fever ? (yes/no): ");
         String fever = scanner.nextLine();

         System.out.print("Do you have cough ? (yes/no): ");
         String cough = scanner.nextLine();

         System.out.print("Do you have sore throat ? (yes/no): ");
         String soreThroat = scanner.nextLine();

    System.out.print("Do you have chest pain? (yes/no): ");
    String chestPain = scanner.nextLine();

    System.out.print("Do you have joint pain? (yes/no): ");
    String jointPain = scanner.nextLine();

    if (fever.equalsIgnoreCase("yes") && cough.equalsIgnoreCase("yes")){
        System.out.println("You may have the flu");

    }else if(fever.equalsIgnoreCase("yes") && soreThroat.equalsIgnoreCase("yes")){
        System.out.println("You may have a Throat Infection ");

    }else if(chestPain.equalsIgnoreCase("yes")){
        System.out.println("You may have a heart related issue. Please see a doctor ");
    
    }else if(jointPain.equalsIgnoreCase("yes")){
        System.out.println("You may have arthritis");
    }else{
        System.out.println("Diagnosis unclear.Please consult a doctor ");
    }
    scanner.close();

    }
}