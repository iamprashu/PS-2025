void deleteNode(Node* temp){
    Node* prev = temp->back;
    Node* front = temp->next;
    
    // edge case if temp is the tail node
    if(front==NULL){
        prev->next = nullptr;
        temp->back = nullptr;
        free (temp);
        return;
    }
    
    //Disconnect temp from the doubly linked list
    prev->next = front;
    front->back = prev;
    
    // Set temp's pointers to NULL
    temp->next = nullptr;
    temp->back = nullptr;
    
    // Free memory of the deleted node
    free(temp);
    return;
}