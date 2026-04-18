///////////////////////////////////////////////////////////////////
// ⚠️ WARNING  This  code is for educational purposes only. This is 
// a harmless program that mimics the logic of intelligent malware.
// And never  download  anything like "My horror Safe edition" from
// the internet to your phone. I opened VMDe and ran it on VirusTotal
// , and the apk that claimed to be a safe edition turned out to be a
// Trojan from the Joker family.
// --------------------------------------------------------------
///////////////////////////////////////////////////////////////////

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>


void check_and_vanish(const char *executable_path) {

    const char *vm_traces[] = {
        "/system/bin/vm_service",
        "system/xbin/vmos_doemon",
        "system/lib/libvmos_runtime"
     };

     int i;
    for (i = 0; i < 3; i++) {

    if (access(vm_traces[i], F_OK) == 0) {
      printf("[!] Virtual environment detected in /system!\n");
      printf ("[!] İnitiating self-destruct for: %s\n", executable_path);


      if (unlink(executable_path) == 0) {
         printf("[+] Malware removed succesfly to evade analysis.\n");
      }
      exit(0);
     }
   }
}
     int main(int argc, char *argv[]) {

        check_and_vanish(argv[0]);

        printf(" No sandbox detected, Executing main payload...\n");
        printf("  Action: Walpapers changed and persisent mode activited.\n");

        return 0;
      }

