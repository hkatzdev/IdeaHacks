<script>
	/**
	 * @typedef {import("$lib/types/ImageInfo").ImageInfo} ImageInfo
	 */

	/** @type {ImageInfo[]} */
	export let images;
</script>

{#each images as image}
	<img src={image.imageURL} alt={image.altText} class="automaticResize" />
	{#if image.newLine}
		<br />
	{/if}
{/each}

<style>
	@import '$lib/styles/automaticResize';
</style>
