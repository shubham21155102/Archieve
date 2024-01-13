#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <semaphore.h>

#define THREAD_NUM 16

sem_t semaphore;

void* routine(void* args) {
    printf("(%d) Waiting in the login queue\n", *(int*)args);
    sem_wait(&semaphore);
    printf("(%d) Logged in\n", *(int*)args);
    sleep(rand() % 5 + 1);
    printf("(%d) Logged out\n", *(int*)args);
    sem_post(&semaphore);
    free(args);
}

int main(int argc, char *argv[]) {
    pthread_t th[THREAD_NUM];
    sem_init(&semaphore, 0, 32);
    int i;
    for (i = 0; i < THREAD_NUM; i++) {
        int* a = malloc(sizeof(int));
        *a = i;
        if (pthread_create(&th[i], NULL, &routine, a) != 0) {
            perror("Failed to create thread");
        }
    }

    for (i = 0; i < THREAD_NUM; i++) {
        if (pthread_join(th[i], NULL) != 0) {
            perror("Failed to join thread");
        }
    }
    sem_destroy(&semaphore);
    return 0;
}
// (0) Waiting in the login queue
// (1) Waiting in the login queue
// (4) Waiting in the login queue
// (1) Logged in
// (5) Waiting in the login queue
// (5) Logged in
// (0) Logged in
// (6) Waiting in the login queue
// (6) Logged in
// (7) Waiting in the login queue
// (7) Logged in
// (2) Waiting in the login queue
// (2) Logged in
// (3) Waiting in the login queue
// (3) Logged in
// (8) Waiting in the login queue
// (8) Logged in
// (4) Logged in
// (10) Waiting in the login queue
// (10) Logged in
// (11) Waiting in the login queue
// (11) Logged in
// (12) Waiting in the login queue
// (12) Logged in
// (9) Waiting in the login queue
// (9) Logged in
// (13) Waiting in the login queue
// (13) Logged in
// (14) Waiting in the login queue
// (14) Logged in
// (15) Waiting in the login queue
// (15) Logged in
// (17) Waiting in the login queue
// (17) Logged in
// (19) Waiting in the login queue
// (19) Logged in
// (20) Waiting in the login queue
// (20) Logged in
// (21) Waiting in the login queue
// (21) Logged in
// (16) Waiting in the login queue
// (16) Logged in
// (22) Waiting in the login queue
// (22) Logged in
// (18) Waiting in the login queue
// (18) Logged in
// (24) Waiting in the login queue
// (24) Logged in
// (25) Waiting in the login queue
// (25) Logged in
// (26) Waiting in the login queue
// (26) Logged in
// (23) Waiting in the login queue
// (23) Logged in
// (27) Waiting in the login queue
// (27) Logged in
// (28) Waiting in the login queue
// (30) Waiting in the login queue
// (30) Logged in
// (31) Waiting in the login queue
// (31) Logged in
// (28) Logged in
// (33) Waiting in the login queue
// (33) Logged in
// (32) Waiting in the login queue
// (29) Waiting in the login queue
// (29) Logged in
// (36) Waiting in the login queue
// (36) Logged in
// (37) Waiting in the login queue
// (37) Logged in
// (32) Logged in
// (34) Waiting in the login queue
// (34) Logged in
// (39) Waiting in the login queue
// (40) Waiting in the login queue
// (40) Logged in
// (35) Waiting in the login queue
// (35) Logged in
// (41) Waiting in the login queue
// (41) Logged in
// (42) Waiting in the login queue
// (42) Logged in
// (38) Waiting in the login queue
// (38) Logged in
// (44) Waiting in the login queue
// (44) Logged in
// (45) Waiting in the login queue
// (45) Logged in
// (39) Logged in
// (46) Waiting in the login queue
// (46) Logged in
// (43) Waiting in the login queue
// (43) Logged in
// (47) Waiting in the login queue
// (47) Logged in
// (48) Waiting in the login queue
// (48) Logged in
// (49) Waiting in the login queue
// (49) Logged in
// (50) Waiting in the login queue
// (50) Logged in
// (51) Waiting in the login queue
// (51) Logged in
// (52) Waiting in the login queue
// (52) Logged in
// (53) Waiting in the login queue
// (53) Logged in
// (54) Waiting in the login queue
// (54) Logged in
// (56) Waiting in the login queue
// (56) Logged in
// (57) Waiting in the login queue
// (57) Logged in
// (58) Waiting in the login queue
// (58) Logged in
// (59) Waiting in the login queue
// (59) Logged in
// (60) Waiting in the login queue
// (60) Logged in
// (61) Waiting in the login queue
// (61) Logged in
// (62) Waiting in the login queue
// (62) Logged in
// (63) Waiting in the login queue
// (63) Logged in
// (64) Waiting in the login queue
// (64) Logged in
// (65) Waiting in the login queue
// (65) Logged in
// (67) Waiting in the login queue
// (67) Logged in
// (88) Waiting in the login queue
// (89) Waiting in the login queue
// (88) Logged in
// (89) Logged in
// (90) Waiting in the login queue
// (90) Logged in
// (92) Waiting in the login queue
// (92) Logged in
// (93) Waiting in the login queue
// (93) Logged in
// (68) Waiting in the login queue
// (68) Logged in
// (69) Waiting in the login queue
// (69) Logged in
// (70) Waiting in the login queue
// (94) Waiting in the login queue
// (70) Logged in
// (94) Logged in
// (71) Waiting in the login queue
// (71) Logged in
// (72) Waiting in the login queue
// (73) Waiting in the login queue
// (72) Logged in
// (73) Logged in
// (55) Waiting in the login queue
// (55) Logged in
// (96) Waiting in the login queue
// (96) Logged in
// (74) Waiting in the login queue
// (74) Logged in
// (75) Waiting in the login queue
// (75) Logged in
// (76) Waiting in the login queue
// (76) Logged in
// (77) Waiting in the login queue
// (80) Waiting in the login queue
// (80) Logged in
// (98) Waiting in the login queue
// (98) Logged in
// (79) Waiting in the login queue
// (79) Logged in
// (81) Waiting in the login queue
// (81) Logged in
// (82) Waiting in the login queue
// (99) Waiting in the login queue
// (85) Waiting in the login queue
// (85) Logged in
// (82) Logged in
// (99) Logged in
// (66) Waiting in the login queue
// (100) Waiting in the login queue
// (87) Waiting in the login queue
// (87) Logged in
// (95) Waiting in the login queue
// (101) Waiting in the login queue
// (101) Logged in
// (102) Waiting in the login queue
// (102) Logged in
// (95) Logged in
// (103) Waiting in the login queue
// (103) Logged in
// (97) Waiting in the login queue
// (97) Logged in
// (104) Waiting in the login queue
// (104) Logged in
// (77) Logged in
// (105) Waiting in the login queue
// (105) Logged in
// (106) Waiting in the login queue
// (106) Logged in
// (117) Waiting in the login queue
// (116) Waiting in the login queue
// (116) Logged in
// (118) Waiting in the login queue
// (118) Logged in
// (83) Waiting in the login queue
// (83) Logged in
// (119) Waiting in the login queue
// (119) Logged in
// (107) Waiting in the login queue
// (84) Waiting in the login queue
// (84) Logged in
// (107) Logged in
// (108) Waiting in the login queue
// (108) Logged in
// (109) Waiting in the login queue
// (109) Logged in
// (120) Waiting in the login queue
// (120) Logged in
// (121) Waiting in the login queue
// (121) Logged in
// (86) Waiting in the login queue
// (86) Logged in
// (66) Logged in
// (122) Waiting in the login queue
// (122) Logged in
// (100) Logged in
// (123) Waiting in the login queue
// (123) Logged in
// (91) Waiting in the login queue
// (91) Logged in
// (111) Waiting in the login queue
// (111) Logged in
// (78) Waiting in the login queue
// (78) Logged in
// (112) Waiting in the login queue
// (124) Waiting in the login queue
// (124) Logged in
// (114) Waiting in the login queue
// (114) Logged in
// (127) Waiting in the login queue
// (130) Waiting in the login queue
// (131) Waiting in the login queue
// (110) Waiting in the login queue
// (131) Logged in
// (110) Logged in
// (113) Waiting in the login queue
// (113) Logged in
// (115) Waiting in the login queue
// (115) Logged in
// (125) Waiting in the login queue
// (126) Waiting in the login queue
// (126) Logged in
// (133) Waiting in the login queue
// (128) Waiting in the login queue
// (133) Logged in
// (127) Logged in
// (128) Logged in
// (136) Waiting in the login queue
// (136) Logged in
// (129) Waiting in the login queue
// (129) Logged in
// (139) Waiting in the login queue
// (137) Waiting in the login queue
// (139) Logged in
// (132) Waiting in the login queue
// (141) Waiting in the login queue
// (142) Waiting in the login queue
// (144) Waiting in the login queue
// (145) Waiting in the login queue
// (142) Logged in
// (147) Waiting in the login queue
// (148) Waiting in the login queue
// (117) Logged in
// (147) Logged in
// (150) Waiting in the login queue
// (151) Waiting in the login queue
// (150) Logged in
// (151) Logged in
// (140) Waiting in the login queue
// (140) Logged in
// (154) Waiting in the login queue
// (155) Waiting in the login queue
// (143) Waiting in the login queue
// (141) Logged in
// (157) Waiting in the login queue
// (157) Logged in
// (143) Logged in
// (159) Waiting in the login queue
// (159) Logged in
// (134) Waiting in the login queue
// (112) Logged in
// (135) Waiting in the login queue
// (149) Waiting in the login queue
// (135) Logged in
// (130) Logged in
// (153) Waiting in the login queue
// (155) Logged in
// (156) Waiting in the login queue
// (156) Logged in
// (132) Logged in
// (146) Waiting in the login queue
// (146) Logged in
// (134) Logged in
// (144) Logged in
// (138) Waiting in the login queue
// (125) Logged in
// (138) Logged in
// (153) Logged in
// (137) Logged in
// (152) Waiting in the login queue
// (148) Logged in
// (152) Logged in
// (149) Logged in
// (154) Logged in
// (158) Waiting in the login queue
// (145) Logged in
// (158) Logged in
// (39) Logged out
// (7) Logged out
// (12) Logged out
// (31) Logged out
// (46) Logged out
// (11) Logged out
// (20) Logged out
// (59) Logged out
// (56) Logged out
// (100) Logged out
// (122) Logged out
// (126) Logged out
// (131) Logged out
// (128) Logged out
// (142) Logged out
// (25) Logged out
// (37) Logged out
// (79) Logged out
// (102) Logged out
// (69) Logged out
// (55) Logged out
// (94) Logged out
// (123) Logged out
// (74) Logged out
// (132) Logged out
// (81) Logged out
// (140) Logged out
// (137) Logged out
// (143) Logged out
// (156) Logged out
// (154) Logged out
// (134) Logged out
// (145) Logged out
// (33) Logged out
// (104) Logged out
// (158) Logged out
// (45) Logged out
// (47) Logged out
// (58) Logged out
// (73) Logged out
// (65) Logged out
// (97) Logged out
// (144) Logged out
// (30) Logged out
// (50) Logged out
// (62) Logged out
// (66) Logged out
// (41) Logged out
// (68) Logged out
// (80) Logged out
// (82) Logged out
// (116) Logged out
// (83) Logged out
// (136) Logged out
// (151) Logged out
// (157) Logged out
// (112) Logged out
// (159) Logged out
// (155) Logged out
// (61) Logged out
// (49) Logged out
// (2) Logged out
// (29) Logged out
// (118) Logged out
// (84) Logged out
// (24) Logged out
// (98) Logged out
// (108) Logged out
// (5) Logged out
// (28) Logged out
// (42) Logged out
// (88) Logged out
// (14) Logged out
// (17) Logged out
// (21) Logged out
// (77) Logged out
// (95) Logged out
// (9) Logged out
// (36) Logged out
// (103) Logged out
// (109) Logged out
// (139) Logged out
// (13) Logged out
// (129) Logged out
// (117) Logged out
// (38) Logged out
// (138) Logged out
// (114) Logged out
// (150) Logged out
// (111) Logged out
// (141) Logged out
// (110) Logged out
// (130) Logged out
// (147) Logged out
// (6) Logged out
// (60) Logged out
// (67) Logged out
// (90) Logged out
// (93) Logged out
// (92) Logged out
// (72) Logged out
// (99) Logged out
// (101) Logged out
// (8) Logged out
// (153) Logged out
// (4) Logged out
// (44) Logged out
// (70) Logged out
// (135) Logged out
// (15) Logged out
// (32) Logged out
// (89) Logged out
// (0) Logged out
// (26) Logged out
// (27) Logged out
// (51) Logged out
// (87) Logged out
// (119) Logged out
// (107) Logged out
// (133) Logged out
// (16) Logged out
// (43) Logged out
// (52) Logged out
// (105) Logged out
// (91) Logged out
// (54) Logged out
// (124) Logged out
// (113) Logged out
// (127) Logged out
// (125) Logged out
// (19) Logged out
// (23) Logged out
// (3) Logged out
// (53) Logged out
// (10) Logged out
// (18) Logged out
// (22) Logged out
// (78) Logged out
// (121) Logged out
// (1) Logged out
// (86) Logged out
// (40) Logged out
// (75) Logged out
// (64) Logged out
// (34) Logged out
// (146) Logged out
// (71) Logged out
// (120) Logged out
// (35) Logged out
// (96) Logged out
// (76) Logged out
// (106) Logged out
// (85) Logged out
// (148) Logged out
// (48) Logged out
// (57) Logged out
// (63) Logged out
// (149) Logged out
// (115) Logged out
// (152) Logged out