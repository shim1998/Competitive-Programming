import java.io.*;
import java.util.*;

public class SwapNodesInPairs {
    public ListNode swapPairs(ListNode head) {
        if(head == null || head.next == null)
            return head;
        ListNode dup = head.next, prev = null;
        while(head != null && head.next != null){
            ListNode nextPair = head.next.next;
            if(prev != null)
                prev.next = head.next;
            head.next.next = head;
            head.next = nextPair;
            prev = head;
            head = head.next;
        }
        return dup;
    }
}
