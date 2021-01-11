#

#获取ip地址
Get_IP(){
    ip=$(wget -qO- -t1 -T2 ipinfo.io/ip)
    if [[ -z "${ip}" ]]; then 
        ip=$(wget -qO- -t1 -T2 api.ip.sb/ip)
        if [[ -z "${ip}" ]]; then 
            ip=$(wget -qO- -t1 -T2 members.3322.org/dyndns/getip)
            if [[ -z "${ip}" ]]; then                                                                                                                 
                ip="VPS_IP"
            fi   
        fi   
    fi   
}

Get_IP
echo ip:${ip}