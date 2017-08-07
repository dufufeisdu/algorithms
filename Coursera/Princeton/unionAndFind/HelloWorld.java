public class HelloWorld{
    public boolean []a;
    HelloWorld(){
    a = new boolean[3];
    a[0] = true;
    }
        public static void main(String [] args){
            HelloWorld h = new HelloWorld();
        System.out.println(h.a[0]);
       }
}