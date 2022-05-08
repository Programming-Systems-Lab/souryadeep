#define KBUILD_MODNAME "filter"
#include <linux/bpf.h>
#include <linux/if_ether.h>
#include <linux/ip.h>
#include <linux/in.h>
#include <linux/udp.h>

/*xdp_md defined in /include/uapi/linux/bpf.h*/
int udpfilter(struct xdp_md *ctx) {
  bpf_trace_printk("got a packet\n");
  void *data = (void *)(long)ctx->data;
  void *data_end = (void *)(long)ctx->data_end;

  /*ethhdr defined in: /include/uapi/linux/if_ether.h*/
  struct ethhdr *eth = data;
  if ((void*)eth + sizeof(*eth) <= data_end) {

    /*iphdr: defined in /include/uapi/linux/ip.h*/  
    struct iphdr *ip = data + sizeof(*eth);
    if ((void*)ip + sizeof(*ip) <= data_end) {
      if (ip->protocol == IPPROTO_UDP) {

	/*udphdr: defined in /include/uapi/linux/udp.h*/
        struct udphdr *udp = (void*)ip + sizeof(*ip);
        if ((void*)udp + sizeof(*udp) <= data_end) {
          if (udp->dest == ntohs(7999)) {
            bpf_trace_printk("udp port 7999\n");
            udp->dest = ntohs(7998);
          }
        }
      }
    }
  }
  return XDP_PASS;
  //return XDP_TX;
  //return XDP_REDIRECT
}

