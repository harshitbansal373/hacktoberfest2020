public class MakeString{
    
    public static void main(String[] args){
        makePoetry();
    }

    public static void makePoetry(){
        String text = "Orwell uses the commonest English surname,\n Smith, to suggest his symbolic value and the name Winston to evoke Churchill’s patriotic appeals for “blood, sweat and tears” \n during the Second World War.\n Winston is middle-aged and physically weak so he hasn’t the traditional characteristics of the hero. \n He works at the Ministry of Truth and he wants to maintain a spiritual and moral integrity so when he was alone he writes on an old diary trying to remain sane in \n a such disorienting world. In the first and in the second part of the novel Orwell expresses his views through Winston so the protagonist of the novel \nand the narrator seem like one.";
        int i;
        for(i = 0; i < text.length(); i++){
            System.out.printf("%c", text.charAt(i));
            try{
                Thread.sleep(75);//0.5s pause between characters
            }catch(InterruptedException ex){
                Thread.currentThread().interrupt();
            }
        }
}
}