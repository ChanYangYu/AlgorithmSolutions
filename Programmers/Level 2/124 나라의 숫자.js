function check(s) {
    const stack = [];
    const size = s.length;
    
    for(let i = 0; i < size; i++){
        if(s[i] === '(' || s[i] === '{' || s[i] === '[')
            stack.push(s[i]);
        else if(s[i] === ')' && stack[stack.length-1] === '('){
            stack.pop();
        }
        else if(s[i] === '}' && stack[stack.length-1] === '{'){
            stack.pop();
        }
        else if(s[i] === ']' && stack[stack.length-1] === '['){
            stack.pop();
        }
        else
            return false;
    }
    
    return stack.length === 0;
}

function solution(s) {
    var answer = 0;
    
    for(let i = 0; i < s.length; i++){
        if(check(s))
            answer++;
        s = s.slice(1) + s[0];
    }
    return answer;
}