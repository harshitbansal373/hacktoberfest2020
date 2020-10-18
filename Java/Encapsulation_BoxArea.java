import java.util.Random;

class box {
  private int height;
  private int width;
  private int length;
  int randomWithRange(int max)
  {
    int range = (max - 1) + 1;     
    return (int)(Math.random() * range) + 1;
  }
  public void setValue(int h, int w) {
    height = h;
    width = w;
    length = randomWithRange(10);
  }
    public int getBoxValue() {
     return height * width * length;
  }
}

class coreEncap {
  public static void main(String args[]) {
     box obj = new box();
     obj.setValue(1,2);
     System.out.print(obj.getBoxValue());
  }
}