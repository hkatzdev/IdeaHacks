<script>

	import { browser } from "$app/environment";

</script>

{#if browser}
<script src="https://accounts.google.com/gsi/client" async></script>
{/if}
<div
	id="g_id_onload"
	data-client_id="407146302691-3h6dv8f44d38sr40pn3i3ql3s2164b16.apps.googleusercontent.com"
	data-context="use"
	data-ux_mode="redirect"
	data-login_uri="http://localhost:5173/login/api"
	data-auto_prompt="false"
></div>

<div
	class="g_id_signin"
	data-type="standard"
	data-shape="pill"
	data-theme="outline"
	data-text="continue_with"
	data-size="large"
	data-logo_alignment="left"
></div>
