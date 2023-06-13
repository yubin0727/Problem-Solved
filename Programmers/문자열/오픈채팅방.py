def solution(record):
    answer = []
    idName = {}
    status = []
    for sent in record:
        tmp = sent.split()
        if tmp[0] != "Leave":
            idName[tmp[1]] = tmp[2]
        if tmp[0] != "Change":
            status.append([tmp[0], tmp[1]])
    for i in range(len(status)):
        if status[i][0] == "Enter":
            answer.append(idName[status[i][1]]+"님이 들어왔습니다.")
        else:
            answer.append(idName[status[i][1]]+"님이 나갔습니다.")
    
    return answer