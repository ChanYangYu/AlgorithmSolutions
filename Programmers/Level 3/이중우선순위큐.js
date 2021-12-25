function PriorityQueue(compare) {
  const queue = [];

  this.top = () => (queue.length === 0) ? undefined : queue[0];
    
  this.empty = () => queue.length === 0;

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
      return 0;
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
      
      if(cur !== parent){
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

function solution(operations) {
    const counting = {};
    const maxHeap = new PriorityQueue((a, b) => a < b);
    const minHeap = new PriorityQueue((a, b) => a > b);
    
    operations.forEach((operation) =>{
        const [cmd, num] = operation.split(' ');
        
        if(cmd === 'I'){
            const number = Number(num);
            maxHeap.push(number);
            minHeap.push(number);
            
            if(counting[num] === undefined){
                counting[num] = 1;
            }
            else{
                counting[num]++;
            }
        }
        else if(num === '1'){
            while(!maxHeap.empty()){
                const top = maxHeap.pop();
                
                if(counting[top] !== 0){
                    counting[top]--;
                    break;
                }
            }
        }
        else{
            while(!minHeap.empty()){
                const top = minHeap.pop();
                
                if(counting[top] !== 0){
                    counting[top]--;
                    break;
                }
            }
        }
    })
    
    while(!minHeap.empty()){
        const top = minHeap.top();

        if(counting[top] !== 0){
            break;
        }
        minHeap.pop();
    }
    
    while(!maxHeap.empty()){
        const top = maxHeap.top();

        if(counting[top] !== 0){
            break;
        }
        maxHeap.pop();
    }
    const answer = [maxHeap.pop(), minHeap.pop()];
    return answer;
}