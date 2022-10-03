package ds3;

import java.util.ArrayList;

public class MiniHashTable {

    Slot[] table = null;

    MiniHashTable(int size) {
        table = new Slot[size];
    }
    class Slot {
        String data;
        String key;
        Slot next = null;

        Slot() { }
        Slot(String key, String data) {
            this.key = key;
            this.data = data;
        }
    }
    public int hashFunc(String key) {
        return (int)key.charAt(0) % this.table.length;
    }

    public void addSlotCloseHashing(String key, String value) {
        int address = hashFunc(key);
        if(this.table[address] != null) {
            if(table[address].key.equals(key)){
                table[address].data = value;
            } else {
                int idx = 1;
                while(table[address + idx] != null) {
                    if(table[address + idx].key.equals(key)) {
                        table[address + idx].data = value;
                        return;
                    } else {
                        idx++;
                        if(idx > this.table.length) {
                            System.out.println("용량 초과!!");
                            return;
                        }
                    }
                }
                table[address+idx] = new Slot(key, value);
            }
        } else {
            table[address] = new Slot(key, value);
        }
    }
    public String getSlotCloseHashing(String key) {
        int address = hashFunc(key);
        if(table[address] != null) {
            if(table[address].key.equals(key)) {
                return table[address].data;
            } else {
                int current = address + 1;
                while(table[current] != null) {
                    if(table[current].key.equals(key)) {
                        return table[current].data;
                    } else {
                        current++;
                    }
                    if(current > table.length) {
                        System.out.println("용량 초과!");
                        return null;
                    }
                }
                return null;
            }
        } else {
            return null;
        }
    }
    public void addSlot(String key, String value) {
        int address = hashFunc(key);
        if(this.table[address] != null) {
            if(table[address].key.equals(key)) {
                table[address].key = key;
            } else {
                Slot pSlot = this.table[address];
                while(pSlot.next != null) {
                    pSlot = pSlot.next;
                    if (pSlot.key.equals(key)) {
                        pSlot.key = key;
                        return;
                    }
                }
                pSlot.next = new Slot(key, value);
            }
        } else {
            this.table[address] = new Slot(key, value);
        }
    }
    public ArrayList<Slot> getSlot(String key) {
        ArrayList<Slot> list = new ArrayList<>();
        int address = hashFunc(key);
        if(this.table[address] == null) {
            return null;
        } else {
            if(this.table[address].next == null) {
                list.add(this.table[address]);
                return list;
            } else {
                Slot pSlot = this.table[address];
                while(pSlot.next != null) {
                    pSlot = pSlot.next;
                    list.add(pSlot);
                }
                return list;
            }
        }
    }
    public boolean isSlot(String key) {
        int address = hashFunc(key);
        if(this.table[address] == null) {
            return false;
        } else {
            if(this.table[address].next == null) {
                if(table[address].key.equals(key)) {
                    return true;
                } else {
                    return false;
                }
            } else {
                Slot pSlot = this.table[address];
                while(pSlot.next != null) {
                    pSlot = pSlot.next;
                    if(pSlot.key.equals(key)) {
                        return true;
                    }
                }
                return false;
            }
        }
    }
    public void listPrint() {
        System.out.println();
        System.out.println("        <전화번호부>");
        for(int i=0 ; i<this.table.length ; i++) {
            print(i);
        }
    }
    public void print(int i) {
        if(this.table[i] == null) {
            System.out.println(((i<9) ? "0" : "") + (i+1) +". [xxx] - [xxx-xxxx-xxxx]");
        } else {
            System.out.print(((i<9) ? "0" : "") + (i+1) + ". [" + this.table[i].key + "] - [" + this.table[i].data + "]");
            if(this.table[i].next != null) {
                Slot pSlot = table[i];
                while(pSlot.next != null) {
                    pSlot = pSlot.next;
                    System.out.print(" -> [" + pSlot.key + "] - [" + pSlot.data + "]");
                }
            }
            System.out.println();
        }
    }
}
