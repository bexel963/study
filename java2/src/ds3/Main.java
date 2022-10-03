package ds3;

import java.util.ArrayList;

public class Main {
    public static void main(String[] args) {

        MiniHashTable hash = new MiniHashTable(20);

        hash.addSlot("홍길동", "010-1234-0601");
        hash.addSlot("임꺽정", "010-4532-5633");
        hash.addSlot("유관순", "010-4621-7531");
        hash.addSlot("장보고", "010-7863-6666");
        hash.addSlot("이순신", "010-3999-2567");
        hash.addSlot("lim jae hyung", "010-3999-2567");
        hash.addSlot("lim sun min", "010-3999-2567");
        hash.addSlot("lim ji sun", "010-3999-2567");
        hash.addSlot("lim ji sun", "010-3999-2567");

        hash.addSlotCloseHashing("홍삼이", "000-0000-0000");
        hash.addSlotCloseHashing("이재명", "000-0000-0000");
        hash.addSlotCloseHashing("이재명", "000-0000-0000");
        hash.listPrint();

        System.out.println(hash.getSlotCloseHashing("이재명"));
        System.out.println("----------------------------");
        ArrayList<MiniHashTable.Slot> slotList = hash.getSlot("lim jae hyung");
        for(int i=0 ; i<slotList.size() ; i++) {
            System.out.println(slotList.get(i).key + ", " + slotList.get(i).data);
        }

        System.out.println(hash.isSlot("lim ji sun"));

    }
}
