function PriorityQueue(compare) {
  const queue = [];
    
  this.empty = () => queue.length === 0;

  this.top = () => {
    if (queue.length === 0){
      throw new Error('Error : queue큐에 top()이 없습니다.');
    }
    else{
      return queue[0];
    }
  }

  this.push = (some) => {
    queue.push(some);
    let cur = queue.length -1;
    let parent = Math.floor((cur-1)/2);
    
    while(parent >= 0){
      if(compare(queue[parent], queue[cur])){
        const tmp = queue[parent];
        queue[parent] = queue[cur];
        queue[cur] = tmp;
        cur = parent;
        parent = Math.floor((cur-1)/2);
      }
      else{
        break;
      }
    }
  }

  this.pop = () => {
    if(queue.length === 0){
      throw new Error('Error : queue에 pop()할 요소가 없습니다.');
    }
    
    if(queue.length === 1){ 
      return queue.pop();
    }
     
    const ret = queue[0];
    const last = queue.pop();
    const size = queue.length;
    let cur = 0;
    
    queue[0] = last;      
    while(cur < queue.length){
      const parent = cur;
      const left = 2*cur+1;
      const right = 2*cur+2;
      
      if(left < size && compare(queue[cur], queue[left])){
        cur = left;
      }

      if(right < size && compare(queue[cur], queue[right])){
        cur = right;
      }
      
      if(cur !== parent) {
        const tmp = queue[parent];
        queue[parent] = queue[cur];
        queue[cur] = tmp;
      }
      else{
        break;
      }
    }
    return ret;
  }
}


function solution(n, works) {
    var answer = 0;
    
    const pq = new PriorityQueue((a, b) => a < b);
    
    works.forEach((work) => pq.push(work));
    
    while(n-- && !pq.empty()){
        const w = pq.pop();
        
        if(w-1 === 0){
            continue;
        }
        else{
            pq.push(w-1);
        }
    }
    
    while(!pq.empty()){
        const w = pq.pop();
        
        console.log(w);
        answer += w * w;
    }
    return answer;
}