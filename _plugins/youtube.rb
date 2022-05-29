require "jekyll"

class YouTubeEmbed < Liquid::Tag

  def initialize(tagName, youtube_id, tokens)
    super
    @youtube_id = youtube_id.strip
  end

  def render(context)
    tmpl_path = File.join Dir.pwd, "_includes", "youtube.html"
    if File.exist?(tmpl_path)
      tmpl = File.read tmpl_path
      site = context.registers[:site]
      tmpl = (Liquid::Template.parse tmpl).render site.site_payload.merge!({"youtube_id" => @youtube_id})
    else
      %Q{<style>.embed-container { position: relative; padding-bottom: 56.25%; height: 0; overflow: hidden; max-width: 100%; } .embed-container iframe, .embed-container object, .embed-container embed { position: absolute; top: 0; left: 0; width: 100%; height: 100%; }</style><div class='embed-container'>    <iframe title="YouTube video player" width="640" height="390" src="//www.youtube.com/embed/#{ @youtube_id }" frameborder="0" allowfullscreen></iframe></div>}
    end
  end

  Liquid::Template.register_tag "youtube", self
end