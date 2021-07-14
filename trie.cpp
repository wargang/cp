struct node {
    struct node* child[2];
    int end;
};

struct node *getNode() {
    node *tmp = (node *)malloc(sizeof(node));
    tmp->child[0] = tmp->child[1] = NULL;
    tmp->end = 0;
    return tmp;
}

void insert(node *root, int x) {
    node *tmp = root;
    for (int i = 30; i >= 0; i--) {
        int ch = 0;
        if (x & (1ll << i)) ch = 1;
        if (tmp->child[ch] == NULL) tmp->child[ch] = getNode();
        tmp->end++;
        tmp = tmp->child[ch];
    }
    tmp->end++;
}

void remove(node *root, int x) {
    node *tmp = root;
    for (int i = 30; i >= 0; i--) {
        int ch = 0;
        if (x & (1ll << i)) ch = 1;
        if (tmp->child[ch] == NULL) tmp->child[ch] = getNode();
        tmp->end--;
        tmp = tmp->child[ch];
    }
    tmp->end--;
}
