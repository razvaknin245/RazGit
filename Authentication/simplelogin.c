
#include <security/pam_appl.h>
#include <security/pam_misc.h>
#include <stdio.h>

#define MYPAM "mypam"
static struct pam_conv conv =
    {
        misc_conv,
        NULL};

int main()
{
    pam_handle_t *pamh = NULL;
    int retval;
    const char *user = "libuser";

    retval = pam_start(MYPAM, user, &conv, &pamh);

    if (retval == PAM_SUCCESS)
        retval = pam_authenticate(pamh, 0); /* is user really user? */

    if (retval == PAM_SUCCESS)
        retval = pam_acct_mgmt(pamh, 0); /* permitted access? */

    /* This is where we have been authorized or not. */

    if (retval == PAM_SUCCESS)
    {
        fprintf(stdout, "Authenticated\n");
    }
    else
    {
        fprintf(stdout, "Not Authenticated\n");
    }

    if (pam_end(pamh, retval) != PAM_SUCCESS)
    { /* close Linux-PAM */
        pamh = NULL;
        fprintf(stderr, "check_user: failed to release authenticator\n");
        exit(1);
    }

    return (retval == PAM_SUCCESS ? 0 : 1); /* indicate success */
}
