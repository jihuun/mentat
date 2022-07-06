// https://velog.io/@soopsaram/Leetcode-24.-Swap-Nodes-in-Pairs

struct ListNode* swapPairs(struct ListNode* head){
    if (!head || !head->next)
        return head;
    struct ListNode* first = head, *second = head->next;

    first->next = swapPairs(second->next);
    second->next = first;

    return second;
}
