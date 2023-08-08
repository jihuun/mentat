/*
["BrowserHistory","visit","visit","visit","back","visit","visit","visit","forward","back","back","forward","visit","forward","back","forward","back","forward","back","visit","forward"]
[["a"],["b"],["c"],["d"],[2],["e"], ["f"], ["g"],[1],[2],[1],[2],["h"],[4],[2],[2],[4],[4],[5],["i"],[3]]
*/
class BrowserHistory {
public:
    struct Node {
        Node *next;
        Node *prev;
        string url;
        int idx;
    };
    Node *head;
    Node *pos;
    Node *new_node(Node *cur, string url, int idx) {
        Node *n = new Node;
        n->next = NULL;
        n->prev = cur;
        n->url = url;
        n->idx = idx;
        return n;
    }

    BrowserHistory(string homepage) {
        head = new_node((Node *)NULL, homepage, 0);
        pos = head;
    }
    
    void visit(string url) { // O(1)
        pos->next = new_node(pos, url, pos->idx + 1);
        pos = pos->next;
    }
    
    string back(int steps) { // O(N)
        if (steps > pos->idx)  {
           pos = head;
           return pos->url;
        }
        while (steps) {
            pos = pos->prev;
            steps--;
        }
        return pos->url;
        
    }
    
    string forward(int steps) { // O(N)
        while (steps) {
            if (!pos->next)
                break;
            pos = pos->next;
            steps--;
        }
        return pos->url;
        
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */