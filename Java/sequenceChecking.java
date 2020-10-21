private boolean sequenceOrderChecking(String username) {
        boolean flag = true;
        String password = username.toUpperCase();
        char [] passwordArray = password.toCharArray();

        for(int i=0;i<username.length()-2;i++){
            char a = passwordArray[i];
            char b = passwordArray[i+1];
            char c = passwordArray[i+2];

            if(Character.isLetter(a)&& Character.isLetter(b) && Character.isLetter(c)){
               flag =  this.checkingValue(a,b,c);
            }

            if(Character.isDigit(a)&& Character.isDigit(b) && Character.isDigit(c)){
                flag = this.checkingValue(a,b,c);
            }
        }
        return flag;
    }
