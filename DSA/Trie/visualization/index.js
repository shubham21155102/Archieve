class TrieNode{
    constructor(){
        this.children = new Map();
        this.isEnd = false;
    }
}
class Trie{
    constructor(){
        this.root = new TrieNode();
    }
    insert(word){
        let node=this.root;
        for(let i=0;i<word.length;i++){
            let c=word[i];
            if(!node.children.has(c)){
                node.children.set(c,new TrieNode());
            }
            node=node.children.get(c);
        }
        node.isEnd=true;
    }
    search(word){
        let node=this.root;
        for(let i=0;i<word.length;i++){
            let c=word[i];
            if(!node.children.has(c)){
                return false;
            }
            node=node.children.get(c);
        }
        return node.isEnd;
    }
    startsWith(prefix){
        let node=this.root;
        for(let i=0;i<prefix.length;i++){
            let c=prefix[i];
            if(!node.children.has(c)){
                return false;
            }
            node=node.children.get(c);
        }
        return true;
    }
}
const trie=new Trie();
trie.insert("apple");
console.log(trie.search("apple"));   //true
console.log(trie.search("app"));     //false
console.log(trie.startsWith("app")); //true
trie.insert("app");