package gram04_ObjectOrientedProgramming1;

import java.util.Arrays;

class BlockTest {
    static {
        System.out.println("클래스 초기화 블럭 호출!!");
    }
    {
        System.out.println("인스턴스 초기화 블럭 호출!!");
    }
    BlockTest() {
        System.out.println("생성자 호출!!");
    }
}

class StaticBlockTest {
    static int[] arr = new int[10];
    static {
        for(int i=0 ; i<arr.length ; i++) {
            arr[i] = (int)(Math.random()*100) + 1;
        }
    }
}
class Product {
    static int count = 0;
    int serialNo;
    int price;
    int size;
    {
        ++count;
        serialNo = count;
    }
    Product() {
        this(1_000_000, 20);
    }
    Product(int price, int size) {
        this.price = price;
        this.size = size;
    }
    @Override
    public String toString() {
        return "[SN:" + serialNo + "]";
    }
}
class Document {
    static int count = 0;
    String name;

    Document() {
        this("제목없음" + ++count);
    }
    Document(String name) {
        this.name = name;
        System.out.println("문서 " + this.name + "가 생성되었습니다.");
    }
}
public class InitializationBlock {
    public static void main(String[] args) {
        BlockTest bt = new BlockTest();
        BlockTest bt2 = new BlockTest();
        BlockTest bt3 = new BlockTest();
        BlockTest bt4 = new BlockTest();

        StaticBlockTest sbt = new StaticBlockTest();
        System.out.println(Arrays.toString(sbt.arr));

        System.out.println("\n===========================================\n");

        Product p = new Product();
        System.out.println(p);
        Product p2 = new Product();
        System.out.println(p2);
        Product p3 = new Product();
        System.out.println(p3);
        Product p4 = new Product();
        System.out.println(p4);
        Product p5 = new Product();
        System.out.println(p5);

        System.out.println("\n===========================================\n");

        Document doc = new Document();
        Document doc2 = new Document("자바.txt");
        Document doc3 = new Document();
        Document doc4 = new Document();
    }
}
