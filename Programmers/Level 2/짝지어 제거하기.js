function Stack() {
    this.arr = [];
    
    this.pop = () => this.arr.pop();
    this.push = (n) => this.arr.push(n);
    this.top = () => this.arr[this.arr.length-1];
    this.empty = () => this.arr.length === 0;
}

function solution(s)
{
    var answer = 0;
    const stack = new Stack();
    
    for(let i = 0; i < s.length; i++){
        if(!stack.empty() && stack.top() === s[i]){
            stack.pop();
        }
        else{
            stack.push(s[i]);
        }
    }
    
    answer = (stack.empty()) ? 1 : 0
    return answer;
}