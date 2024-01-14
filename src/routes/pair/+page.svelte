<script>
	import { onMount } from "svelte";

  onMount(() => {
    screen.orientation.addEventListener("change", (event) => {
      // @ts-ignore
      const type = event.target.type;
      // @ts-ignore
      const angle = event.target.angle;
    });

  })
</script>

