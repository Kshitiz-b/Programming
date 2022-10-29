public class relationships {
    
}

class person {
    String name;
    int code;

}

class account extends person {
    float pay;
}

class admin extends person {
    int experience;
}

class master extends account, admin {
    
}